// RunJacobi.cpp for CS319 Lab 6
// What: Demonstrates the use of Jacobi's method for
//     solving a linear system of equations. Based on
//     02TestMatrix.cpp from Week 8, but with a few minor improvements.
// To compile this programme, you will need
//   Matrix08.h, Vector08.h, Matrix08.cpp and Vector08.cpp
// from Week 8.
// See http://www.maths.nuigalway.ie/~niall/CS319/Week08/
// Author: Niall Madden
//   Date: 06/03/2016


//Modified by: Owen McDonnell
//ID NUmber: 14361511
#include <iostream>
#include <stdlib.h>

#include "Vector08.h"
#include "Matrix08.h"


double tol;

void Jacobi(matrix &A, vector &b, vector &v,
            unsigned int &count, double tol);

int main(void )
{
  std::cout << "Enter tolerance limit: ";
  std::cin >> tol;

  // Our matrix is of size NxN
  unsigned int N=6;

  matrix A(N);
  vector x(N), b(N); // A*x=b

  // Initialise the entries of A. We choose the off-diagonal entries
  // to be random numbers between -3 and 3. The  diagonal entries,
  // will be the sum of the absolute value of the others +1.
  // We make the random entries in [-3,3] by picking a random number
  // between 0 and 6, and then subtracting 3.
  // The entries in the solution vector, x,  are all 1.
  // Then we choose the solution right-hand side so A*x=b
  for (unsigned int i=0; i<N; i++)
  {
    A.setij(i,i, 0.0);
    for (unsigned int j=0; j<N; j++)
      if (i != j)
      {
	A.setij(i,j, (double) (rand()%6-3));
	A.setij(i,i, A.getij(i,i) + abs(A.getij(i,j)));
      }
    x.seti(i, 1.0 );
    A.setij(i,i, A.getij(i,i)+1.0);
  }

  std::cout << "A=" << std::endl;
  A.print();

  b=A*x;
  std::cout << "b=A*x" << std::endl;
  b.print();

  // We will now use the Jacobi method to approximate the solution
  // The Jacobi solution is called estimate
  vector estimate(N);
  unsigned int iterations;

  estimate.zero();
  // Call Jacobi's method. Want to have the norm of the residual less
  //  than 10^(-4)
  Jacobi(A, b, estimate, iterations, tol);
  std::cout << "Jacobi took " << iterations << " iterations. Estimate is : "
	    << std::endl;
  estimate.print();

  //Gauss Seidel Method
  vector xnew(N);
  unsigned int iters = 0;
  for(unsigned i=0; i<N; i++){
    xnew.seti(i, b.geti(i));
    for(unsigned j=0; j<N; j++){
       if( j != i){
         xnew.seti(i,xnew.geti(i)-A.getij(i,j));
         xnew.seti(i, xnew.geti(i)/A.getij(i,i));
         iters++;
       }
    }
  }
  std::cout << "xnew=" << std::endl;
  std::cout << "Gauss took: " << iters << " iterations" << std::endl;
  xnew.print();

  std::cout << "The norm of the error is: ";
  vector error=x-estimate;
  std::cout << error.norm() << std::endl << std::endl;

  return (0);
}

// Use Jacobi's method to solve Ax=b,
// On entry : x is the initial guess
// On exit  : x is the estimate for the solution
void Jacobi(matrix &A, vector &b, vector &x,
            unsigned int &count, double tol)
{
  unsigned int maxIters;
  std::cout << "Enter Maximum number of iterations: ";
  std::cin >> maxIters;

  unsigned int N= A.size();
  count =0;
      if ( (N != b.size()) || (N != x.size() ) )
        std::cout << "Jacobi: error - A must be the same size as b,x\n";

      // Form the diagonal and off-diagonal matrices
      matrix Dinv(N), T(N);
      for (unsigned int i=0; i<N; i++)
        for (unsigned int j=0; j<N; j++)
          if (j != i)
          {
    	T.setij(i,j, -A.getij(i,j));
    	Dinv.setij(i,j,0.0);
          }
          else
          {
    	T.setij(i,j, 0.0);
    	Dinv.setij(i,j, 1.0/A.getij(i,j));
          }

      // Implement the algorithm:
      vector r(N);
      do
      {
        if(count > maxIters){
          //call a convergence error
          std::cerr << "Max iterations exceeded,solution does not converge";
          break;
        }
        else{
          count++;
          x = Dinv*(b+T*x); // set x = inverse(D)*(b+T*x)
          r=b-A*x; // set r=b-A*r
        }
      }   while ( r.norm() > tol);

}
