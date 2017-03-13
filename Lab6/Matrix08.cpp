// File:     Matrix08.cpp (version: Week08)
// Author:   Niall Madden (NUI Galway) Niall.Madden@NUIGalway.ie
// Date:     01/03/2017  (Week 8 of 1617-CS319)
// What:     Header file for matrix class
// See also: Matrix08.h

#include <iostream>
#include "Vector08.h"
#include "Matrix08.h"

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

//////////////////////////////////////////
// Everything above this is from Week 7 //
// Everything below this is from Week 8 //
//////////////////////////////////////////

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
}/*
vector &operator/(vector &u, matrix &L){
  unsigned int N = L.size();
  vector x(N);
  for (unsigned int i=0; i<N; i++)
  {
    double y=0;
    for (unsigned int j=0; j<N; j++){
      y += x.entries[i/N+j]/u.geti(j);
      x.seti(i,y);
    }
  }
  return(x);
}
*/
