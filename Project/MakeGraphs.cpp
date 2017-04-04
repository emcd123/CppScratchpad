// MakeGraphs.cpp CS319 Lab 7
//   What: Generate the adjacency matrices for some networks.
// Author: Niall Madden
//   Date: March 2017

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream> // For files
#include <string>
#include <sstream> // For manipulating string streams

#include "Vector09.h" // From Week 9
#include "Matrix09.h" // From Week 9

#include <algorithm> // Niall added this

void quickSort(matrix arr[], int left, int right);
bool operator<(matrix& m1, matrix& m2);

int main(void ){
  unsigned int N=10;
  unsigned int NumberOfMatrix=10;

  double p=20; // probability of an edge being present, as a percentage
  matrix M[NumberOfMatrix](N);
  std::cout << "Generating the matrix:" << std::endl;
  srand(time(NULL));

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

  std::cout << "-------------------------------" << std::endl <<
    "Performing std::sort " << std::endl;
  size_t size = sizeof(M) / sizeof(M[0]);
  std::sort(M, M+size);
  for(unsigned int i=0; i<NumberOfMatrix; i++) {
      std::cout << "M" << "[" << i << "]" << "=" << std::endl;
    M[i].print();
    std::cout << "M" << "[" << i << "].edgeCount()=" << M[i].edgeCount() << std::endl;
  }
  return (0);
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
          tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
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
