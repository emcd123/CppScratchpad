// File:     Vector08.cpp (version: Week08)
// Author:   Niall Madden (NUI Galway) Niall.Madden@NUIGalway.ie
// Date:     01/03/2017  (Week 8 of 1617-CS319)
// What:     Header file for vector class
// See also: Vector08.h

#include <iostream>
#include <math.h>
#include "Vector08.h"

// default constructor
// Note: the version from Week07 did not use the "this" pointer
vector::vector (unsigned int N)
{
  this->N = N;
  entries = new double[N];
}

// copy constructor
vector::vector (const vector &old_vector)
{
  N = old_vector.N;
  entries = new double[N];
  for (unsigned int i=0; i<N; i++)
    entries[i] = old_vector.entries[i];
}

// destructor
vector::~vector ()
{
  delete [] entries;
}

void vector::seti (unsigned int i, double x)
{
  if (i<N)
    entries[i]=x;
  else
    std::cerr << "vector::seti(): Index out of bounds." << std::endl;
}

double vector::geti (unsigned int i)
{
  if (i<N)
    return(entries[i]);
  else
  {
    std::cerr << "vector::geti(): Index out of bounds." << std::endl;
    return(0);
  }
}


void vector::print (void)
{
  for (unsigned int i=0; i<N; i++)
    std::cout << "[" << entries[i] << "]" << std::endl;
}

double vector::norm (void)
{
  double x=0;
  for (unsigned int i=0; i<N; i++)
    x+=entries[i]*entries[i];
  return (sqrt(x));
}

void vector::zero(void)
{
  for (unsigned int i=0; i<N; i++)
    entries[i]=0;
}

////////////////////////////////////////////////////////
// Everything above this is, except the copy constructor,
//     is from Week 7.
// Everything below this is from Week 8
////////////////////////////////////////////////////////

// Overload the = operator.
vector &vector::operator=(const vector &b)
{
  if (this == &b)
    return(*this); // Taking care for self-assignment

  delete [] entries; // In case memory was already allocated

  N = b.N;
  entries = new double[b.N];
  for (unsigned int i=0; i<N; i++)
    entries[i] = b.entries[i];

  return(*this);
}

// Overload the + operator. For Lectures 10 and 11
vector vector::operator+(vector b)
{
  vector c(N); // Make c the size of a
  if (N != b.N)
    std::cerr << "vector::+ : cant add two vectors of different size!" << std::endl;
  else
    for (unsigned int i=0; i<N; i++)
      c.entries[i] = entries[i] + b.entries[i];

  return(c);
}

// Overload the unary minus (-) operator. As in b=-a;
vector vector::operator-(void)
{
  vector b(N); // Make b the size of a
  for (unsigned int i=0; i<N; i++)
    b.entries[i] = -entries[i];
  return(b);
}

// Overload the binary minus (-) operator. As in c=a-b
// This implementation reuses the unary minus (-) operator
vector vector::operator-(vector b)
{
  vector c(N); // Make b the size of a
  if (N != b.N)
    std::cerr << "vector:: operator- : dimension mismatch!"
	      << std::endl;
  else
    c = *this + (-b);
  return(c);
}
