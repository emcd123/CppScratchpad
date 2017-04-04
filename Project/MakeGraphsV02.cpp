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

int main(void )
{
  unsigned int N=4;
  unsigned int NumberOfMatrix=10;
  
  double p=20; // probability of an edge being present, as a percentage
  matrix M[NumberOfMatrix](N);
  std::cout << &M[0];
  std::cout << "\nGenerating the matrix:" << std::endl;
  srand(time(NULL));

  for(unsigned int k=0; k<NumberOfMatrix; k++){
    //std::cout << "DEBUG: making matrix " << k << std::endl;
    for (unsigned int i=0; i<N; i++){
      for (unsigned int j=0; j<N; j++){
        if ( (i!=j) && (rand()%101) <=p ){
          M[k].setij(i, j, 1);
        }
        else{
	  M[k].setij(i, j, 0);
        }
      }
      //want to change the probability for an edge each time,but want to keep it above 0.1 and below a certain bound
    }
    std::cout << "M" << "[" << k << "]" << "=" << std::endl;
    M[k].print();
    std::cout << "M" << "[" << k << "].edgeCount()=" << M[k].edgeCount() << std::endl;
  }
  //std::cout << "DEBUG Finished generating the matrix:" << std::endl;

/*  std::cout << "DEBUG Let's compare:" << std::endl;
  for (unsigned int i=0; i<N-1; i++)    
    for (unsigned int j=i+1; j<N; j++)
    {
      bool tmp = (M[i] < M[j]);
      std::cout << "M[" << i << "] < M[" << j << "]=" <<  tmp << std::endl;
    }
  std::cout << "Number of edges: " << M[1].edgeCount();
*/
  std::cout << "-------------------------------" << std::endl <<
    "Performing std::sort " << std::endl;
  size_t size = sizeof(M) / sizeof(M[0]); 
  std::sort(M, M+size);
//  std::cout << "Performing QuickSort algorithm " << std::endl;
//  quickSort(M,0,N);
  for(unsigned int i=0; i<NumberOfMatrix; i++) {
      std::cout << "M" << "[" << i << "]" << "=" << std::endl;
    M[i].print();
    std::cout << "M" << "[" << i << "].edgeCount()=" << M[i].edgeCount() << std::endl;
  }
//  std::cout << &M[0];
  return (0);
}

void quickSort(matrix arr[], int left, int right) {
  int i = left, j = right;
  matrix tmp;
  matrix pivot = arr[(left + right) / 2];
  arr[i].print();
  std::cout << j << std::endl;


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
