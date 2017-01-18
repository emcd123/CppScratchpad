//C++ program to implement
//various sorting techniques

#include <iostream>
#include <stdlib.h> //To use random number functions

using namespace std;

//1st ALGORITHM
//Bubble sorting
//Complexity O(n^2)
int Bubble(){
  const int n = 5;
  int array[n];

  /* initialize random seed: */
  srand (time(NULL));
  //populate array with random integers
  for(int i = 0; i< n; i++){
    array[i] = rand() %10;
  }
  for(int j= 0; j< n; j++){
    cout << array[j];
  }
  for(int k = 0; k<n; k++){
    //loop through array,
    //check if k > k+1
    //if so swap the index of k and k+1
  }
  return 0;
}


int main(){
  int bubble;
  bubble = Bubble();
  cout << bubble;
  return 0;
}
