/*
   CS319; Lab 3
   Written by: Owen McDonnell, 14361511
   Converting a decimal number into a binary number
*/
#include <iostream>
#include <stdlib.h> // for exit

#define MAX_STACK 10

class stack {
private:
  char *contents;
  int top;
public:
  stack (void);
  stack (unsigned int StackSize);
  ~stack(void);
  void init(void );
  void push(char c);
  char pop(void );
  bool emptyCheck(void);
  bool fullCheck(void);
};
stack::stack(void){
  top=0;
  contents = new char[MAX_STACK];
}
stack::stack(unsigned int StackSize){
  top=0;
  contents = new char[StackSize];
}
stack::~stack(){
  delete [] contents;
}
bool stack::emptyCheck(void){
  if(top == 0){ //Stack is Empty
     return(true);
  }
  else{
     return(false);
  }
}
bool stack::fullCheck(void){
  if(top == MAX_STACK){
    return true;
  }
  else{
    return false;
  }
}
void stack::push(char c){
  if(fullCheck()){
    std::cerr << "Cannot push onto a full stack..";
    exit(EXIT_FAILURE); //to terminate the programme if max number of iterations met
  }
  else{
    contents[top]=c;
    top++;
  }
}
char stack::pop(void){
    if(emptyCheck()){
      std::cerr << "Cannot pop on an empty stack..";
      return((char)NULL);
    }
    else{
      top--;
      return(contents[top]);
    }
}
/*

1. Create a stack
2. Enter a decimal number, which has to be converted into its equivalent binary form.
3. iteration1 (while number > 0)
    3.1 digit = number % 2
    3.2 Push digit into the stack
    3.3 If the stack is full
         3.3.1 Print an error
         3.3.2 Stop the algorithm
    3.4 End the if condition
    3.5 Divide the number by 2
4. End iteration1

5. iteration2 (while stack is not empty)
    5.1 Pop digit from the stack
    5.2 Print the digit
6. End iteration2
7. STOP

*/
int main(){
  //Cretae an instance of a stack
  stack s1(8);
  unsigned int number;//the decimal integer to be converted
  int digit;

  std::cout << "Enter a decimal integer number to be converted: ";
  std::cin >> number;

  while(number>0){
    digit = number % 2;
    s1.push(digit);//Has error check included in the code
    number = number /2;
  }
  while(! s1.emptyCheck()){
    int d = s1.pop();
    std::cout << d ;
  }
  std::cout << "\n";
  return 0;
}
