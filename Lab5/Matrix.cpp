// File:     Matrix.cpp (Methods for matrix class)
// Author:   Niall Madden (NUI Galway) Niall.Madden@NUIGalway.ie
// Date:     22/02/2017  (Week 7 of 1617-CS319)
// See also: Matrix.h and 02TestMatrix.cpp 

#include <iostream>
using namespace std;
#include "Matrix.h"

matrix::matrix (unsigned int Size) 
{
  N = Size;
  entries = new double [N*N];
}

void matrix::setij (unsigned int i, unsigned int j, double x)
{
  if (i<N && j<N)
    entries[i*N+j]=x;
  else
    cerr << "matrix::setij(): Index out of bounds." << std::endl;
}

double matrix::getij (unsigned int i, unsigned int j)
{
  if (i<N && j<N)
    return(entries[i*N+j]);
  else
  {
    cerr << "matrix::getij(): Index out of bounds." << std::endl;
    return(0);
  }
}

void matrix::print (void)
{
//   std::cout << "matrix is of size " << M << "-by-" << N << std::std::endl;
  for (unsigned int i=0; i<N; i++)
  {
    for (unsigned int j=0; j<N; j++)
      std::cout << "[" << entries[i*N+j] << "]";
    std::cout << std::endl;
  }
}
