// File:     03Jacobi.cpp (Jacobi's method for solving systems)
// Author:   Niall Madden (NUI Galway) Niall.Madden@NUIGalway.ie
// Date:     22/02/2017  (Week 7 of 1617-CS319)
// What:     Solving a linear system of equations with Jacobi's method
// See also: Vector.h, Matrix.h, Vector.cpp, and Matrix.cpp

#include <iostream>
#include <stdlib.h>

#include "Vector.h"
#include "Matrix.h"

//  c=alpha*a + beta*b where a,b are vectors; alpha, beta are scalars
void VecAdd (vector &c, vector &a, vector &b,
             double alpha=1.0, double beta=1.0);

//  Compute a matrix-vector product (v=A*u)
void MatVec(matrix &A, vector &u, vector &v);

// Use Jacobi's method to solve a least-squares problem
void Jacobi(matrix &A, vector &b, vector &v,
	    unsigned int &count, double tol=1e-6);

int main(void )
{
  unsigned int N=3;

  matrix A(N);
  vector x(N), b(N);

  for (unsigned int i=0; i<N; i++)
  {
    for (unsigned int j=0; j<N; j++)
      if (i==j)
	A.setij(i, j, (double)(3*N));
      else A.setij(i,j, (double)(1+i+j));
    x.seti(i, 1.0);
  }

  std::cout << "A=" << std::endl;
  A.print();

  std::cout << "x=" << std::endl;
  x.print();

  std::cout << "Setting b=A*x" <<std::endl;
  MatVec(A, x, b);
  std::cout << "b=" << std::endl;
  b.print();

  vector est(N);
  unsigned int iterations;

  est.zero();
  Jacobi(A, b, est, iterations, 1e-3);

  std::cout << "Jacobi took " << iterations << ". Estimate is : " << std::endl;
  est.print();

  return (0);
}


//////////////////
//  Set v=A*u
void MatVec(matrix &A, vector &u, vector &v)
{
  unsigned int N;
  N = A.size();

  if ( (N != u.size()) || ( N != v.size() ) )
    std::cerr << "dimension mismatch in MatVec " << std::endl;
  else
  {
    for (unsigned int i=0; i<N; i++)
    {
      double x=0;
      for (unsigned int j=0; j<N; j++)
	x += A.getij(i,j)*u.geti(j);
      v.seti(i,x);
    }
  }
}

//  alpha*a + beta*b where a,b are vectors; alpha, beta are scalars
void VecAdd (vector &c, vector &a, vector &b, double alpha, double beta)
{
  unsigned int N;
  N = a.size();

  if ( (N != b.size()) )
    std::cerr << "dimension mismatch in VecAdd " << std::endl;
  else
  {
    for (unsigned int i=0; i<N; i++)
      c.seti(i, alpha*a.geti(i)+beta*b.geti(i) );
  }
}

// Use Jacobi's method to solve Ax=b,
// On entry : x is the initial guess
// On exit  : x is the estimate for the solution
void Jacobi(matrix &A, vector &b, vector &x,
	    unsigned int &count, double tol)
{
  unsigned int N=A.size();
  count=0;
  if ( (N != b.size()) || (N != x.size() ) )
    std::cout << "Jacobi: error - A must be the same size as b,x\n";

  matrix Dinv(N), T(N);   // The diagonal and off-diagonal matrices

  for (unsigned int i=0; i<N; i++)
    for (unsigned int j=0; j<N; j++)
      if (j != i) {
	T.setij(i,j, -A.getij(i,j));
	Dinv.setij(i,j,0.0);
      }
      else {
	T.setij(i,j, 0.0);
	Dinv.setij(i,j, 1.0/A.getij(i,j));
      }

  // Now implement the algorithm:
  vector d(N), r(N);
  do
  {
    count++;
    MatVec(T,x,d);      // Set d=T*x
    VecAdd(d, b, d);    // set d=b+d (so d=b+T*x)
    MatVec(Dinv, d, x); // set x = inverse(D)*(b+T*x)

    MatVec(A, x, r);    // set r=A*x
    VecAdd(r, b, r, 1.0, -1.0); // set r=b-A*r

  }   while ( r.norm() > tol);
}
