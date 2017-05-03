#include <iostream>

int main(){
/*
  2015/2016
*/
  //Q1 a)
  /*
     Estimates the smallest positive
    double that is representable
  */
  double smallestDouble;
  smallestDouble = 1;
  while ((smallestDouble/2)>0) {
    smallestDouble = smallestDouble/2;
  }
  cout << smallestDouble << " = Smallest positive double"  << "\n";

  /*
     Largest positive double
  */
   double largestDouble;
   largestDouble=1;
   while(isfinite(largestDouble*2) == 1 ){
     largestDouble= largestDouble*2;
   }
   cout << largestDouble << " = largest positive double" << "\n";

  /*
      Estimate the smallest positive double x,
      such that x+1 is distinguishable from 1
  */
  double machineEpsilon;
  machineEpsilon =1;
  while((1+machineEpsilon/2) != 1){
    machineEpsilon = machineEpsilon/2;
  }
  cout << machineEpsilon << " = Smallest positive double such that its distinguishable from 1" << "\n";

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
 return 0;
}