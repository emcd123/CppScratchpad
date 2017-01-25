/*
   C++ implementation of polynomial interpolation
   Using some function F(x) to find a polynomial p(x)
   which interpolates the function
   then return the interpolated y-values
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>


using namespace std;


int F(int x){
   //float y_values = exp(cos(x/2));
   float y_values = 1/(pow(x,2)+1);
   return y_values;
}

int Lagrange(){

  return 0;
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

  int f_y[3];//our y_values from evaluating f(x)

  for(int i=0; i<3; i++){
    float func;
    func = F(x[i]);
    cout << func;
    f_y[i] = func;
  }
  for(int k=0; k<3; k++){
    cout << f_y[k];


  return 0;
}
