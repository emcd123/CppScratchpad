/*
   Largest Prime Factor
*/
#include <iostream>

using namespace std;

//int isPrime(int x);
//int isFactor(int x);


int main(){
  int n = 0;
  int factorList[n];
  const int x = 13195;
  for(int j = 2; j< x; j++){
    if(x%j == 0){
      factorList[n] = j;
      //cout << factorList[n] << "\n";
      n++;
    }
  }
  for(int z= 0; z< n; z++){
    for(int i = 2; i<9; i++){
      if(factorList[z]%i != 0){
        cout << factorList[z] << "\n";
      }
    }
  }
  return 0;
}


//int primeFactor(){}

/*
int isFactor(int x){
  //to create a list of the factors of x
  int n = 0;
  int factorList[n];
  for(int j = 2; j< x+1; j++){
    if(x%j == 0){
      factorList[n] = j;
      n++;
    }
  }
  return factorList;
}

int isPrime(int x){
  //A function to check primality of x
  for(int i = 2; i<9; i++){
    if(x%i == 0){
      return 0;
    }
    else{
      return 1;
    }
  }
  return 0;
}
*/
