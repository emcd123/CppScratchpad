
#include <iostream>
#include <math.h>


bool isPrime(int x){
  if (x < 2) return false;
  for(int i=2; i<= sqrt(x); i++) {
    if ((x%i) == 0) return false;
  }
  return true;
}

int main(){

  int n = 10;
  for (int i = 2;i<n;i++){
    if(isPrime(i)==1){
    //std::cout << isPrime(n);
      std::cout << i <<" => This is a prime \n";
    }
    else{
      std::cout << i <<" => This is NOT a prime \n";
    }
  }
  return 0;
}
