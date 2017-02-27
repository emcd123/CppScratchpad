/*

   Assignment: Part 1
*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h> // for exit


double bound;//Global variable for the bound,global as its outside main()
double Bisection(double a,double b, int &k, double ObjFn(double));

double F(double x){
  return((x)*sqrt(10-x));
}
double Planes(double x){
  return sqrt(((500*x)*(500*x))+((100-800*x)*(100-800*x)));
}
int main(){
  std::cout << "Enter the bound value: \n ";
  std::cin >> bound;

  double a =0    , b = 10-a;
  double c;
  int k = 0;

  c = Bisection(a,b,k,F);// just add the function to the arguments,then call the function bisection again

  std::cout << "The maximum of the function between "
      << a << " and " << 10-a << " is at "
	    << std::setprecision(10) << c << std::endl;
      std::cout << "Number of iterations in loop: " << k << "\n";
//  double p1 =0    , p2 = 100;
  //double min;
  //int k1 = 0;

  //min  = Bisection(p1,p2,k1,Planes);

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
