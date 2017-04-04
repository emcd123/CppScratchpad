// File:     Matrix09.cpp (version: Week09)
// Author:   Niall Madden (NUI Galway) Niall.Madden@NUIGalway.ie
// Date:     08/03/2017  (Week 9 of 1617-CS319)
// What:     Header file for matrix class
// See also: Matrix09.h
// Changes from Matrix08.cpp:
//    change #include to include latest header files.
//    Added zero() method

#include <iostream>
#include "Vector09.h"
#include "Matrix09.h"

// Basic constructor. See below for copy constructor.
matrix::matrix (unsigned int Size)
{
  N = Size;
  entries = new double [N*N];
}

matrix::~matrix(void)
{
  delete [] entries;
}

void matrix::setij (unsigned int i, unsigned int j, double x)
{
  if (i<N && j<N)
    entries[i*N+j]=x;
  else
    std::cerr << "matrix::setij(): Index out of bounds." << std::endl;
}

double matrix::getij (unsigned int i, unsigned int j)
{
  if (i<N && j<N)
    return(entries[i*N+j]);
  else
  {
    std::cerr << "matrix::getij(): Index out of bounds." << std::endl;
    return(0);
  }
}

void matrix::print (void)
{
//   std::cout << "matrix is of size " << M << "-by-" << N << std::endl;
  for (unsigned int i=0; i<N; i++)
  {
    for (unsigned int j=0; j<N; j++)
      std::cout << "[" << entries[i*N+j] << "]";
    std::cout << std::endl;
  }
}

int matrix::edgeCount(void){
  int edges = 0;
  for (unsigned int i=0; i<N; i++)
    for (unsigned int j=0; j<N; j++)
        edges+=(entries[i*N+j]);
  return(edges);
}

////////////////////////////////////////////////
// Everything above this is from Week 7       //
// Everything below this is from Week 8 and 9 //
////////////////////////////////////////////////

// Matrix copy constructor
matrix::matrix (const matrix &m)
{
  N = m.N;
  entries = new double[N*N];
  for (unsigned int i=0; i<N*N; i++)
    entries[i] = m.entries[i];
}


// Overload the assignment = operator.
matrix &matrix::operator=(const matrix &B)
{
  if (this == &B)
    return(*this); // Taking care for self-assignment

  delete [] entries; // Just in case there was any memory
  // already allocated to this

  entries = new double[(B.N)*(B.N)];
  for (unsigned int i=0; i<N*N; i++)
    entries[i] = B.entries[i];

  return(*this);
}

bool operator<(matrix& m1, matrix& m2){
//  std::cout << "Comparing " << m1.edgeCount() << " with " << m2.edgeCount() <<   std::endl;
  if(m2.edgeCount() < m1.edgeCount()){
    return true;
  }
  else{
    return false;
  }
}

// Overload the operator multiplication (*) for a matrix-vector
// product. Matrix is passed implicitly as "this", the vector is
// passed explicitly. Will return v=(this)*u
vector matrix::operator*(vector u)
{
  vector v(N); // v = A*w, where A is the implicitly passed matrix
  if (N != u.size())
    std::cerr << "Error: matrix::operator* - dimension mismatch"
	      << std::endl;
  else
    for (unsigned int i=0; i<N; i++)
    {
      double x=0;
      for (unsigned int j=0; j<N; j++)
	x += entries[i*N+j]*u.geti(j);
      v.seti(i,x);
    }
  return(v);
}


////////////////////////////////////////////////
// Everything above this is from Week 7 and 8 //
// Everything below this is from Week 9 //
////////////////////////////////////////////////
void matrix::zero (void)
{
  for (unsigned int i=0; i<N; i++)
    for (unsigned int j=0; j<N; j++)
      entries[i*N+j] = 0.0;
}
