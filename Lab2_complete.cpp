// CS319 -- Scientific Computing
// A very basic implementation of a bisection algorithm.
// This is loosely based on Shapira "Solving PDEs in C++", Section 1.20

/*
   Lab 2; CS319]
   Written by Owen McDonnell;1436511
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h> // for exit

double bound;//Global variable for the bound,global as its outside main()
//Prototypes for each fucntion, some called multiple times later
double bisection(double left, double right, int &iterCount);
double recursiveBisection(double a, double b, int &k);
double Bisection(double a, double b, int &k, double ObjFn(double));
double reverseBisection(double a, double b, int &k, double ObjFn(double));

// The objective function,used in part a)-e)
double ObjFn(double x){
  return( exp(x) - 3*x*x + 2*x );
}
//Function for Assignment: Part 2
double Planes(double x){
  return sqrt(pow(500*x,2)+pow(100-800*x,2));
}
//Function for Assignment: Part 1
double F(double x){
  return((x)*sqrt(10-x));
}
int main(){
  std::cout << "Enter the bound value: \n ";
  std::cin >> bound;

  //For parts a)-e)
  double a=-1.0, b=3.0, MAX;
  int k = 0;

  //Just pick which implementation you want to use,the rest are commented out
  //c = bisection(a,b,k);
  MAX = recursiveBisection(a,b,k);
  //c = Bisection(a,b,k,ObjFn);// just add the function to the arguments,then call the function bisection again

  std::cout << "The maximum of the function between "
      << a << " and " << b << " is at "
      << std::setprecision(10) << MAX << std::endl;
      std::cout << "Number of iterations in loop: " << k << "\n";


   std::cout << "\n";

  /*
    Assignment: Part 1
  */
  double d =0    , e = 10-d;
  double max;
  int k1 = 0;

  max = Bisection(d,e,k1,F);// just add the function to the arguments,then call the function bisection again

  std::cout << "The maximum of the function(a*sqrt(b)) between "
      << d << " and " << b << " is at "
	    << std::setprecision(10) << max << std::endl;
      std::cout << "Number of iterations in loop: " << k1 << "\n";
   std::cout << "\n";

   /*
     Assignment: Part 2
  */
  double p1 =0    , p2 = 100;
  double min;
  int k2 = 0;

  min  = reverseBisection(p1,p2,k2,Planes);

  std::cout << "The time(in hours) taken to reach the minimum distance between (the planes),"
      << p1 << " and " << p2 << " is at "
      << std::setprecision(10) << min << std::endl;
      std::cout << "Number of iterations in loop: " << k1 << "\n";

      std::cout << "Minimum distance in km: "<< sqrt(pow(500*min,2)+pow(100-800*min,2));

  std::cout << "\n";
  return(0);
}
/*
   Lab 2; CS319]
   Parts a) -- e)
   Written by Owen McDonnell;1436511
*/
/*
   A recursive implementation of the bisection method
   part d) of lab sheet
   Which counts loop iterations using pass by reference
   Terminates after k iterations if function does not converge
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
      if ((F(c) > F(l)) && (F(c) > F(r))){
          a=l;
          b=r;
      }
      else if (F(l) > F(r)){
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


/*
   Assignment: Part 1
*/
double Bisection(double a, double b, int &k, double ObjFn(double)){
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
   Assignment: Part 2

   Funtions can be passed as an argument to this function,
   Counts loop iterations using pass by reference,
   Terminates after k iterations if function does not converge
*/
double reverseBisection(double a, double b, int &k, double ObjFn(double)){
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

      if ((ObjFn(c) < ObjFn(l)) && (ObjFn(c) < ObjFn(r))){
        a=l;
        b=r;
      }
      else if (ObjFn(l) < ObjFn(r)){
        b=c;
      }
      else{
        a=c;
      }
  }
  return(c);
}
