/*
   Creating a C++ sieve,
   Written by EmcD123
*/

#include <iostream>
#include <math.h>
#include <vector>

void sieve();
bool isPrime(int x);
bool isEven(int a);

int main(){

  sieve();

  //for(int i = 0; i<n; i++){
    //potentialPrimes[n] = i;
  //}
  return 0;
}

void sieve(){
  const int n = 12;

  std::vector <int> potentialPrimes;
  for(int k=2; k<n; k++){
    if(isEven(k) == true){
      potentialPrimes.push_back(k);
    }
  }
  for(unsigned int x=0; x< potentialPrimes.size();x++){
    std::cout << potentialPrimes[x]<<"\n";
  }
  std::vector <int> actuallyPrime;
  for(unsigned int z=0 ;z< potentialPrimes.size(); z++){
    //std::cout << z<< "\n";//works to here!
    if(isPrime(potentialPrimes[z]) == true){
      actuallyPrime.push_back(potentialPrimes[z]);
      std::cout <<"Primes: "<< actuallyPrime[z]<<"\n";
    }
  }
  for(unsigned int y=0 ;y< actuallyPrime.size(); y++){
    //std::cout << actuallyPrime[y]<<"\n";
  }
}

bool isEven(int a){
  if (a < 2) return false;
  for(int i=2; i<10; i=i+2) {
    if ((a%i) == 0) return false;
  }
  return true;
}


bool isPrime(int x){
  if (x < 2) return false;
  for(int i=2; i<= sqrt(x); i++) {
    if ((x%i) == 0) return false;
  }
  return true;
}
