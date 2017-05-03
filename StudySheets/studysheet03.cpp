#include <iostream>

bool Common(int *a, int *b, unsigned int N);

int main(){
  unsigned int N = 5;
  int a[N] = {1, 10, 5, 6};
  int b[N] = {12, 13, 14, 2};

  if(Common(a,b,N)){
  	std::cout << "There are identical elements in these arrays" << std::endl;
  }
  else{
  	std::cout << "No identical elements";
  }
	return 0;
}

bool Common(int *a, int *b, unsigned int N){
  int flag = 0;
  for(unsigned int i=0; i< N; i++){
  	if((a[i] && b[i]) != 0){
	  	if(a[i] == b[i]){
	  		flag++;
	  	}
  	}
  }
  if(flag != 0){
  	return true;
  }
  else{
  	return false;
  }
}