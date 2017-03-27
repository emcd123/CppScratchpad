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

int main(void ){
  unsigned int N=5;
  double p=20; // probability of an edge being present, as a percentage
  matrix M[N](5);

  std::cout << "Generating the matrix:" << std::endl;
  srand(time(NULL));

  for(unsigned int k=0; k<5; k++){
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
  }
  //Now find the number of edges in each graph(matrix)
  // Add up every non zero entry then divide by to find number of edges

  return (0);
}
