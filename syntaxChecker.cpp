/*
  Lab 4: Syntax Checker
  Written by: EmcD123
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX_STACK 10

bool bracketMatch(char c);

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
  if(top == StackSize){
    return true;
  }
  else{
    return false;
  }
}
void stack::push(char c){
  if(fullCheck()){
    std::cerr << "Cannot push onto a full stack..";
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


int main(){
  stack syntaxChecker(5);
  std::ifstream InFile;
  std::ofstream OutFile;
  char c;

  std::string file;
  std::cout<< "Enter name of file to be checked: "<< std::endl;
  std::cin >> file;

  std::cout << "Processing the contents of " << file  << std::endl;
  std::cout << " See file Output.txt for more information." << std::endl;
  InFile.open(file.c_str());
  OutFile.open("Output.txt");

  int i=0;
  InFile.get(c);

  while(! InFile.eof()){
    i++;
    InFile.get(c);
    /*
      Procedure: each character is gotten until end of file is reached
      Then check if that character is a [,],{,},(,)
      if it is one of those, push onto the stack
      find you find its matching character pop it off the stack,
      At the end, if the stack is not empty there is an error
    */
    if(bracketMatch(c)){//finds if a character is a bracket,returns true then push character
      syntaxChecker.push(c);
    }
  }
  OutFile << file << "file contains "
       << i << " characters \n";

  InFile.close();
  OutFile.close();

  while(! syntaxChecker.emptyCheck()){
    std::cout << syntaxChecker.pop() << std::endl;
  }

  return 0;
}


bool bracketMatch(char c){
  if(c == '('){
    return true;
  }
  if(c == ')'){
    return true;
  }
  if(c == '['){
    return true;
  }
  if(c == ']'){
    return true;
  }
  if(c == '{'){
    return true;
  }
  if(c == '}'){
    return true;
  }
  else{
    return false;
  }
}
