/*
   C++ implementation of polynomial interpolation
   Using some function F(x) to find a polynomial p(x)
   which interpolates the function
   then return the interpolated y-values
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;


int F(int x){
   //float y_values = exp(cos(x/2));
   float y_values = x+2;
   return y_values;
}


int main(){


  const int n = 2; //degree of polynomial
  int a = -5;
  int b = 5; // range of the interval
  float h  = (a+b)/n; //distance between point x0,x1,....,xn

  int x[3]; // Our list of points;
  x[0] = a;
  x[1] = h;
  x[2] = b;

  for(int i=0; i<3; i++){
    float func;
    func = F(x[i]);
    cout << func;
  }

  return 0;
}
