/*
  Written By: Owen McDonnell; ID: 14361511
  CS319 - Project

  For info on , refer Doc.txt
  For efficiency analysis see ...

*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream> // For files
#include <string>
#include <sstream> // For manipulating string streams

#include "Vector09.h" // From Week 9
#include "Matrix09.h" // From Week 9

#include <algorithm> // Niall added this
#include <time.h>

void quickSort(matrix arr[], int left, int right);
bool operator<(matrix& m1, matrix& m2);
void bubbleSort(matrix arr[],unsigned int n);
void swap(matrix &p1, matrix &p2);

int main(void ){
  unsigned int N=5;
  unsigned int NumberOfMatrix=4000;

  double p=20; // probability of an edge being present, as a percentage
  matrix M[NumberOfMatrix](N);
  std::cout << "Generating the matrix:" << std::endl;
  srand(time(NULL));
  //Starting the clock
  clock_t t1,t2;
    t1=clock();

  //Generate a matrix
  for(unsigned int k=0; k<NumberOfMatrix; k++){
    for (unsigned int i=0; i<N; i++){
      for (unsigned int j=0; j<N; j++){
        if ( (i!=j) && (rand()%101) <=p ){
          M[k].setij(i, j, 1);
        }
        else{
  	      M[k].setij(i, j, 0);
        }
      }
    }
    std::cout << "M" << "[" << k << "]" << "=" << std::endl;
    M[k].print();
    std::cout << "Number of edges: " << M[k].edgeCount() << std::endl;
  }
  //std::cout << "Performing QuickSort algorithm " << std::endl;
  //quickSort(M,0,N);

  std::cout << "Performing Bubble Sort" << std::endl;
  bubbleSort(M,NumberOfMatrix);

  
  //std::cout << "-------------------------------" << std::endl <<
   // "Performing std::sort " << std::endl;
  //size_t size = sizeof(M) / sizeof(M[0]);
  //std::sort(M, M+size); 
  for(unsigned int i=0; i<NumberOfMatrix; i++) {
      std::cout << "M" << "[" << i << "]" << "=" << std::endl;
    M[i].print();
    std::cout << "M" << "[" << i << "].edgeCount()=" << M[i].edgeCount() << std::endl;
  }
  //Turning off the clock
  t2=clock();
    float diff ((float)t2-(float)t1);
    //cout<<diff<<endl;
    //system ("pause");
  float seconds = diff / CLOCKS_PER_SEC;
  std::cout << seconds << " seconds spent running" << std::endl;
  return (0);
}
void bubbleSort(matrix arr[],unsigned int N){
  for(int i = (N-1); i>1; i--){
    for(int k = 0; k < i; k++){
      if(arr[k+1] < arr[k]){
        swap(arr[k], arr[k+1]);
      }
    }
  }
}
void swap(matrix &p1, matrix &p2) {
   //if ((p1 != NULL) && (p2 != NULL)) {
     matrix temp = p1;
     p1 = p2;
     p2 = temp;
  //}
}
void quickSort(matrix arr[], int left, int right) {
  int i = left, j = right;
  matrix tmp;
  matrix pivot = arr[(left + right) / 2];

  while (i <= j) {
    std::cout << "echo" << std::endl;

    while (arr[i] < pivot){
          i++;
    }
    while (pivot < arr[j]){
          j--;
    }
    if (i <= j) {
/*          tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp; */
          swap(arr[i], arr[j]);
          i++;
          j--;
    }
  }
  if (left < j){
    quickSort(arr, left, j);
  }
  if (i < right){
    quickSort(arr, i, right);
  }
}
