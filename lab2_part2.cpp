/*
   Assignment: Part 2
*/
#include <iostream>
#include <iomanip>
#include <math.h> //for sqrt and pow
#include <stdlib.h> // for exit

double bound;//Global variable for the bound,global as its outside main()
double Bisection(double a,double b, int &k, double ObjFn(double));

double Planes(double x){
  return sqrt(pow(500*x,2)+pow(100-800*x,2));
}

int main(){
  std::cout << "Enter the bound value: \n ";
  std::cin >> bound;

  double p1 =0    , p2 = 100;
  double min;
  int k = 0;

  min  = Bisection(p1,p2,k,Planes);

  std::cout << "The time(in hours) taken to reach the minimum distance between "
      << p1 << " and " << p2 << " is at "
      << std::setprecision(10) << min << std::endl;
      std::cout << "Number of iterations in loop: " << k << "\n";

      std::cout << "Minimum distance in km: "<< sqrt(pow(500*min,2)+pow(100-800*min,2));

  return(0);
}

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
