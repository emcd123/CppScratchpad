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
  double x;
  x = 1;
  while ((x/2)>0) {
    x = x/2;
  }
  cout << x << " = Smallest positive double"  << "\n";

  /*
    Q8 ii) largest positive double
  */
   double y;
   y=1;
   while(isfinite(y*2) == 1 ){
     y= y*2;
   }
   cout << y << " = largest positive double" << "\n";

  /*
     Q8 iii) estimate the smallest positive double x,
     such that x+1 is distinguishable from 1
  */
  double z;
  z =1;
  while((1+z/2) != 1){
    z = z/2;
  }
  cout << z << " = Smallest positive double s.t its distinguishable from 1" << "\n";

  return 0;
}
