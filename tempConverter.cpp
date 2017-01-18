//A program to convert  celsius to fahrenheit

#include <iostream>

//To remove nessecity of std::
using namespace std;

//function to convert temperatures from Clesius to Fahrenheit
int CF_Converter(){
  float fahrenheit;
  float celsius;
  string s;
  cout << "Please input temperature in degrees celsius \n" ;
  cin >> celsius;
  fahrenheit = ((9.0/5.0)*celsius)+ 32;
  return fahrenheit;
}

int FC_Converter(){
  float fahrenheit;
  float celsius;
  string s;
  cout << "Please input temperature in degrees fahrenheit \n" ;
  cin >> fahrenheit;
  celsius = (fahrenheit - 32) / (9.0/5.0);
  return celsius;
}


int main(){

  int input;

  cout << "This is a temperature converter \n";
  cout << "For celsisus fahrenheit conversion type '0' \n";
  cout << "For fahrenheit to celsius conversion type '1' \n";
  cin >> input;

  //while (!(input == 0 || input == 1)) {
  //  cin >> input;
    //if (input != 0 || input != 1) {
      //  cout << "Not a valid input,try again";
        //cin >> input;
    //}
  //}

  if(input == 0){
    float CF;
    CF = CF_Converter();
    cout << "Temperature in fahrenheit is " << CF << " degrees\n";
  }
  if (input == 1){
    float FC;
    FC = FC_Converter();
    cout << "Temperature in celsius is " << FC << " degrees\n";
  }


  return 0;

}
