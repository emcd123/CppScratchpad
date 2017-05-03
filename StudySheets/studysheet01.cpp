
 // Basic constructor. See below for copy constructor.
matrix::matrix (unsigned int Size)
{
  N = Size;
  entries = new double [N*N];
}

//Destructor
matrix::~matrix(void)
{
  delete [] entries;
}

//Matrix copy constructor
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

/*
   Overload the operator multiplication (*) for a matrix-vector
   product. Matrix is passed implicitly as "this", the vector is 
   passed explicitly. Will return v=(this)*u
*/
vector matrix::operator*(vector u){
  vector v(N); // v = A*w, where A is the implicitly passed matrix
  if (N != u.size()){
    std::cerr << "Error: matrix::operator* - dimension mismatch"
        << std::endl;
  }
  else{
    for (unsigned int i=0; i<N; i++){
      double x=0;
      for (unsigned int j=0; j<N; j++)
  x += entries[i*N+j]*u.geti(j);
      v.seti(i,x);
    }
  return(v);
 }


