/*
   Lab 1
   CS319; Scientific Computing
   Name: Owen McDonnell
   ID: 14361511
*/

#include <iostream>
#include <math.h>

using namespace std;

int main(){
  /*
    Q8 i) estimates the smallest positive
    double that is representable
  */
  double smallestDouble;
  smallestDouble = 1;
  while ((smallestDouble/2)>0) {
    smallestDouble = smallestDouble/2;
  }
  cout << smallestDouble << " = Smallest positive double"  << "\n";

  /*
    Q8 ii) largest positive double
  */
   double largestDouble;
   largestDouble=1;
   while(isfinite(largestDouble*2) == 1 ){
     largestDouble= largestDouble*2;
   }
   cout << largestDouble << " = largest positive double" << "\n";

  /*
     Q8 iii) estimate the smallest positive double x,
     such that x+1 is distinguishable from 1
  */
  double machineEpsilon;
  machineEpsilon =1;
  while((1+machineEpsilon/2) != 1){
    machineEpsilon = machineEpsilon/2;
  }
  cout << machineEpsilon << " = Smallest positive double such that its distinguishable from 1" << "\n";

  return 0;
}
