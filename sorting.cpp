//C++ program to implement
//various sorting techniques

#include <iostream>
#include <stdlib.h> //To use random number functions

using namespace std;

//1st ALGORITHM
//Bubble sorting
//Complexity O(n^2)
char Bubble(){
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
  cout << "\n";
  for(int k = 0; k < n; k++){
    //loop through array,
    //check if k > k+1
    //if so swap the index of k and k+1
    if(array[k] > array[k+1]){
      //void swap(int &p1, int &p2);
      swap(array[k], array[k+1]);
    }
  }
  for(int j= 0; j< n; j++){
    cout << array[j];
  }

  return 'e';
 }

void swap(int &p1, int &p2) {
   //if ((p1 != NULL) && (p2 != NULL)) {
     int temp = p1;
     p1 = p2;
     p2 = temp;
  //}
}

int main(){
  //bubble;
  //bubble = Bubble();
  cout << Bubble();
  return 0;
}
