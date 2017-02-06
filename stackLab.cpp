/* 03StackConstructor.cpp
  What: Improvement upon the initial version of the stack class.
        This one uses constructors (but not a destructor).
Author: Niall Madden

Modified by: EmcD123
*/

#include <iostream>
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


int main(void ){
  stack s1(6);

  std::cout << "Pushing CS319" << std::endl;
  s1.push('C');
  s1.push('S');
  s1.push('3');
  s1.push('1');
  s1.push('9');

  std::cout << "Popping ... " << std::endl;

  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;

  //std::cout<< s1.fullCheck() << std::endl;

  return (0);
}
