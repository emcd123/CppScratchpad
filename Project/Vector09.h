// File:     Vector09.h (Version: Week09)
// Author:   Niall Madden (NUI Galway) Niall.Madden@NUIGalway.ie
// Date:     08/03/2017  (Week 9 of 1617-CS319)
// What:     Header file for vector class
// See also: Vector09.cpp 

#include <iostream>   // New for Week 9 for overloading <<

// In case this header files included multiple times.
#ifndef _VECTOR_H_INCLUDED
#define _VECTOR_H_INCLUDED

class vector {
  friend std::ostream &operator<<(std::ostream &, vector &v);
private:
  double *entries;
  unsigned int N;
public:
  vector (unsigned int Size=2);
  vector (const vector &v); // Arg must be passed by value. Why?
  ~vector(void);

  vector &operator=(const vector &b); // overload assignment operator

  const unsigned int size(void) {return N;};
  double geti (unsigned int i);
  void seti (unsigned int i, double x);

  vector operator+(vector b);
  vector operator-(vector b); // binary
  vector operator-(void); // unary

  void print(void);
  double norm(void); // Compute the 2-norm of a vector
  void zero(); // Set entries of vector to zero.
};
 
#endif
