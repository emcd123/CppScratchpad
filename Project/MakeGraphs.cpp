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

int main(void )
{
  unsigned int N=5;
  unsigned int ID;
  double p=15; // probability of an edge being present, as a percentage
  matrix A(N);
  std::ofstream CSVFile;
  std::string FileName;

  std::cout << "Enter your ID number: ";
  std::cin >> ID;

  std::cout << "Seeding the random number generator with " << ID << std::endl;
  srand(ID);

  std::cout << "Generating the matrix:" << std::endl;

  for (unsigned int i=0; i<N; i++)
    for (unsigned int j=0; j<N; j++)
      if ( (i!=j) && (rand()%101) <=p )
	A.setij(i, j, 1);
      else
	A.setij(i, j, 0);

  // Need to check there is at least one entry in each row and each column.
  // This is equivalent to requiring that no vertex by isolated.
  for (unsigned int i=0; i<N; i++)
  {
    int row_count=0;
    for (unsigned int j=0; j<N; j++)
      row_count+=A.getij(i,j);
    if (row_count == 0)
    { // add a new edge, but not a loop
      unsigned int new_edge;
      do {
	new_edge = rand()%N;
      } while (new_edge == i);
      A.setij(i,new_edge, 1);
    }
  }
  for (unsigned int j=0; j<N; j++)
  {
    int col_count=0;
    for (unsigned int i=0; i<N; i++)
      col_count+=A.getij(i,j);
    if (col_count == 0)
    { // add a new edge, but not a loop
      unsigned int new_edge;
      do {
	new_edge = rand()%N;
      } while (new_edge == j);
      A.setij(new_edge, j, 1);
    }
  }

  std::cout << "A=" << std::endl;
  A.print();

  // Now open the file in CSV in write mode
  // First we'll need to convert the ID number to a string

  std::stringstream ss;  //create a stringstream
  ss << std::setw(8) << std::setfill('0') << ID; //add number to the stream
  FileName=ss.str()+".csv";

  std::cout << "FileName: " << FileName << std::endl;

  CSVFile.open(FileName.c_str()); // Open take a "C string" argument
  for (unsigned int i=0; i<N; i++)
  {
    for (unsigned int j=0; j<N-1; j++)
      CSVFile <<  A.getij(i, j) << ",";
    CSVFile << A.getij(i,N-1) << std::endl;
  }

  CSVFile.close( ) ;
  return (0);
}
