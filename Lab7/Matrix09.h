// File: Matrix09.h (version: Week09)
//   What: Header file for matrix class, including overloading = and *
// Author: Niall Madden
//   Date: 09/03/2017
// Note: Implementation for a square matrix
// Changes from Matrix08.h
//    change #include to include latest header files.
//    Added zero() method

#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include "Vector09.h" // Only chance from Vector08.h

class matrix {
private:
  double *entries;
  unsigned int N;
public:
  matrix (unsigned int Size=2);
  matrix (const matrix &m); // New copy constructor
  ~matrix(void);

  matrix &operator=(const matrix &B); // overload assignment operator

  unsigned int size(void) {return (N);};
  double getij (unsigned int i, unsigned int j);
  void setij (unsigned int i, unsigned int j, double x);

  vector operator*(vector u);
  void print(void);

  void zero (void); // New for Week 9
};
#endif
