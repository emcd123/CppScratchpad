/*
    A c++ programme containing the
    individual questions in the online lab sheet
*/
#include <iostream>
#include <cmath>

using namespace std;

int q1(){
  //Q1 from the lab sheet
  //Define a variable
  //initialise it with value 9
  int a;
  a = 9;
  return a;
}


int q2(){
  /*  Q2 from lab sheet
      Input a number,returen an error if outside of range
      Calculate up to n powers of 3 if in range
  */
  int n;
  cout << "Enter an integer betwenn 1 and 19(inclusive): ";
  cin >> n;
  if (n<1 || n>19){
    cout << "Error \n";
    return 0;
  }
  else{
    for(int i = 0; i<(n+1); i++){
      int powers;
      powers = pow(3,i);
      cout << "3^" << n << "=" << powers << "\n";
    }
  }
  return 0;
}

int main(){
  //Executing question 1
  int Q1;
  Q1 = q1();
  cout << Q1 << "\n";

  //Executing Q2
  int Q2;
  Q2 = q2();
  cout << Q2 << "\n";

  return 0;
}
