/*
  Lab 4: Syntax Checker
  Written by: EmcD123
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX_STACK 10

bool openBracketMatch(char c);
bool isComment(char k, char c);

class stack {
private:
  char *contents;
  unsigned int top;
  unsigned int StackSize;
public:
  stack (void);
  stack (unsigned int StackSize);
  ~stack(void);
  void init(void );
  void push(char c);
  char pop(void );
  bool emptyCheck(void) const;
  bool fullCheck(void);
  char peak(void ) const;
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
bool stack::emptyCheck(void) const{
  if(top == 0){ //Stack is Empty
     return(true);
  }
  else{
     return(false);
  }
}
bool stack::fullCheck(void){
  if(top == (StackSize)){
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
      std::cerr << "An opening bracket is missing somewhere";
      return((char)NULL);
    }
    else{
      top--;
      return(contents[top]);
    }
}
char stack::peak(void) const{
    if(emptyCheck()){
      //std::cerr << "An opening bracket is missing somewhere";
      return((char)NULL);
    }
    else{
      return(contents[top]);
    }
}
bool closedBracketMatch(const stack &syntaxChecker,char c);

int main(){
  stack syntaxChecker(5);

  std::ifstream InFile;
  std::ofstream OutFile;
  char c;
//  char k;

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
    if(c == '/' && InFile.peek() == '/'){
      //Now we are in a comment
      std::cout << "There is a comment" << std::endl;
      while(c != '\n'){
        InFile.get(c);
        //std::cout << "1" << std::endl;
      }
    }
    if(openBracketMatch(c)){//finds if a character is a bracket,returns true then push character
      syntaxChecker.push(c);
      //std::cout << c << std::endl;
    }
    if(closedBracketMatch(syntaxChecker,c)){//finds if a character is a bracket,returns true then pop character
      std::cout << syntaxChecker.pop() << std::endl;
    }
  }
  OutFile << file << "file contains "
       << i << " characters \n";

  InFile.close();
  OutFile.close();

  while(! syntaxChecker.emptyCheck()){
    //std::cout << "The match for this type bracket is missing somewhere: ";
    //std::cout << syntaxChecker.pop() << std::endl;
  }
  return 0;
}
bool isComment(char k, char c){
  if(k == '/' && c == '/'){
    return true;
  }
  else{
    return false;
  }
}
bool openBracketMatch(char c){
  if(c == '('){
    return true;
  }
  if(c == '['){
    return true;
  }
  if(c == '{'){
    return true;
  }
  else{
    return false;
  }
}
bool closedBracketMatch(const stack &syntaxChecker ,char c){
  if((syntaxChecker.peak() == '(') && (c == ')')){
    return true;
  }
  if((syntaxChecker.peak() == '[') && (c == ']')){
    return true;
  }
  if((syntaxChecker.peak() == '{') && (c == '}')){
    return true;
  }
  else{
    return false;
  }
}
/*
bool closedBracketMatch(char k, char c){
  if(k == '(' && c == ')'){
    return true;
  }
  if(k == '[' && c == ']'){
    return true;
  }
  if(k == '{' && c == '}'){
    return true;
  }
  else{
    return false;
  }
}
*/
