#include <iostream>
#include <math.h>
int main(){
/*
  2015/2016
*/
  //Q1 a)
  /*
     Estimates the smallest positive
    double that is representable
  */
  double smallestDouble;
  smallestDouble = 1;
  while ((smallestDouble/2)>0) {
    smallestDouble = smallestDouble/2;
  }
  std::cout << smallestDouble << " = Smallest positive double"  << std::endl;

  /*
     Largest positive double
  */
   double largestDouble;
   largestDouble=1;
   while(isfinite(largestDouble*2) == 1 ){
     largestDouble= largestDouble*2;
   }
   std::cout << largestDouble << " = largest positive double" << std::endl;

  /*
      Estimate the smallest positive double x,
      such that x+1 is distinguishable from 1
  */
  double machineEpsilon;
  machineEpsilon =1;
  while((1+machineEpsilon/2) != 1){
    machineEpsilon = machineEpsilon/2;
  }
  std::cout << machineEpsilon << " = Smallest positive double such that its distinguishable from 1" << std::endl;

 return 0;
}