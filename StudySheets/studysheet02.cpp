#include <iostream>
#include <math.h>
#include <string>
using std::string;

string convertBin(unsigned int x);

int main(){
  unsigned int x;
  std::cout << "Enter a number to convert: " << std::endl;
  std::cin >> x;
  std::cout << convertBin(x) << std::endl;
	return 0;
}

string convertBin(unsigned int x){
  string binary = "";
    int mask = 1;
    for(int i = 0; i < 31; i++){
        if((mask & x) != 0){
            binary = "1"+binary;
        }
        else{
            binary = "0"+binary;
        }
        mask<<=1;
    }
	return binary;
}