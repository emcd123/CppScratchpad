//A program to convert  celsius to fahrenheit

#include <iostream>

using namespace std;


int tempConverter(float celsius){
  float fahrenheit;
  fahrenheit = ((9.0/5.0)*celsius)+ 32;
  return fahrenheit;
}

int main(){
  float temp;
  temp = tempConverter(20.1);
  cout << "Temperature in fahrenheit is " << temp << " degrees\n";

  return 0;
}
