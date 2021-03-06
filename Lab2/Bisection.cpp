// CS319 -- Scientific Computing
// A very basic implementation of a bisection algorithm.
// This is loosely based on Shapira "Solving PDEs in C++", Section 1.20

/*
   Lab 2; CS319]
   Parts a) -- e)
   Written by Owen McDonnell;1436511
*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h> // for exit

double bound;//Global variable for the bound,global as its outside main()
double bisection(double left, double right, int &iterCount);
double recursiveBisection(double a, double b, int &k);
double Bisection(double a, double b, int &k, double ObjFn(double));

// The objective function
double f(double x){
  return( exp(x) - 3*x*x + 2*x );
}
// The generalised objective function,used in part e)
double ObjFn(double x){
  return( exp(x) - 3*x*x + 2*x );
}

int main(){
  std::cout << "Enter the bound value: \n ";
  std::cin >> bound;

  double a=-1.0, b=3.0, c;
  int k = 0;

  //Just pick which implementation you want to use,the rest are commented out
  //c = bisection(a,b,k);
  c = recursiveBisection(a,b,k);
  //c = Bisection(a,b,k,ObjFn);// just add the function to the arguments,then call the function bisection again

  std::cout << "The maximum of the function between "
      << a << " and " << b << " is at "
	    << std::setprecision(10) << c << std::endl;
      std::cout << "Number of iterations in loop: " << k << "\n";
  return(0);
}

// FUNCTION: bisection
// ARGUMENTS: (double) a and (double) b
// RETURNS: (double) c, the point where the function f,
//    defined above, achieves its max.
double bisection(double a, double b, int &k){
  double c = (a+b)/2.0;
  const int maxIter = 31;

  while ( (b-a) > bound){
    if (k == maxIter){
      std::cout << "Maximum iterations reached...did not converge \n";
      exit(EXIT_FAILURE); //to terminate the programme if max number of iterations met
    }
    k++;
    c = (a+b)/2.0;
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
  }
    return(c);
}
/*
   Trying to make a more genral bisection algorithm
   For part e) of lab sheet
*/
double Bisection(double a, double b, int &k, double ObjFn(double)){//objective function passed as an argument
  double c = (a+b)/2.0;
  const int maxIter = 31;

  while ( (b-a) > bound){
      if (k == maxIter){
        std::cout << "Maximum iterations reached...did not converge \n";
        exit(EXIT_FAILURE); //to terminate the programme if max number of iterations met
      }
      k++;
      c = (a+b)/2.0;
      double l = (a+c)/2.0, r=(c+b)/2.0;

      if ((ObjFn(c) > ObjFn(l)) && (ObjFn(c) > ObjFn(r))){
        a=l;
        b=r;
      }
      else if (ObjFn(l) > ObjFn(r)){
        b=c;
      }
      else{
        a=c;
      }
  }
  return(c);
}
/*
   A recursive implementation of the bisection method
   part d) of lab sheet
*/
double recursiveBisection(double a, double b,int &k){
  double c = (a+b)/2.0;
  const int maxIter = 31;
  if((b-a) > bound){
    if (k == maxIter){
      std::cout << "Maximum iterations reached...did not converge \n";
      exit(EXIT_FAILURE); //to terminate the programme if max number of iterations met
    }
    k++;
    double c = (a+b)/2.0;
    double l = (a+c)/2.0, r=(c+b)/2.0;
      if ((f(c) > f(l)) && (f(c) > f(r))){
          a=l;
          b=r;
      }
      else if (f(l) > f(r)){
        b=c;
      }
      else{
        a=c;
      }
      return recursiveBisection(a,b,k);
  }
  else{
    return c;
  }
}
