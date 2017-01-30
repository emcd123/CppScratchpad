// CS319 -- Scientific Computing
// A very basic implementation of a bisection algorithm.
// This is loosely based on Shapira "Solving PDEs in C++", Section 1.20
// Author: Niall Madden
// Date: 30/01/2017
// For more, see:  See http://www.maths.nuigalway.ie/~niall/CS319/lab2/
#include <iostream>
#include <iomanip>
#include <math.h>

double bound;

double bisection(double left, double right, int &iterCount);
double recursiveBisection(double a, double b);

// The objective function
double f(double x)
{
  return( exp(x) - 3*x*x + 2*x );
}


int main()
{
  std::cout << "Enter the bound value: \n ";
  std::cin >> bound;

  double a=-1.0, b=3.0, c;
  //int k = 0;

  //c = bisection(a,b,k);
  c = recursiveBisection(a,b);

  std::cout << "The maximum of the function between "
       << a << " and " << b << " is at "
	    << std::setprecision(10) << c << std::endl;
      //std::cout << "Number of iterations in loop: " << k << "\n";

  return(0);
}


// FUNCTION: bsection
// ARGUMENTS: (double) a and (double) b
// RETURNS: (double) c, the point where the function f,
//    defined above, achieves its max.
double bisection(double a, double b, int &k)
{
  double c = (a+b)/2.0;
  const int maxIter = 31;

  while ( (b-a) > bound)
    {
      if (k == maxIter){
        std::cout << "Maximum iterations reached...did not converge \n";
        return 0;
      }
      k++;
      c = (a+b)/2.0;
        double l = (a+c)/2.0, r=(c+b)/2.0;

        if ( (f(c) > f(l)) && (f(c) > f(r)) )
        {
            a=l;
            b=r;
        }
        else if ( f(l) > f(r) )
            b=c;
        else
            a=c;
    }

    return(c);
}

double recursiveBisection(double a, double b){
  double c = (a+b)/2.0;
  if((b-a) > bound){
    double c = (a+b)/2.0;
      double l = (a+c)/2.0, r=(c+b)/2.0;

      if ( (f(c) > f(l)) && (f(c) > f(r)) ){
          a=l;
          b=r;
      }
      else if ( f(l) > f(r) ){
        b=c;
      }
      else{
        a=c;
      }
      return recursiveBisection(a,b);

  }
  else{
    return c;
  }
}
