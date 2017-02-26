/*
  Lab 4: Syntax Checker
  Written by: EmcD123
*/

/******************************************************************************************/
/*                    ChangeLog                                                           */
/* Fixed:  Top function correctly returns top of stack                                    */
/*         Brackets now accurately match with each other                                  */
/*         Brackets in strings and regular '//' style comments are ignored                */
/*         C-style comments(leave until last)                                             */
/*         Error not called when closed bracket exist without an open bracket             */
/*         Have to fix "No errors" message when a closing bracket without opening exists  */
/*         Line Count                                                                     */


/* To Do:                                                                                 */
/*         Checking order of brackets(kind of done,but not satisfactory)                                                     */
/*         Implement a isComment() function to remove excess if statements from main()    */
/*         Need to improve effectiveness of output                                        */
/*         Finding line error that actually occurred on(not possible with current procedure)*/
/******************************************************************************************/

/**************************************************************************************************************
                     Instructions
    Stack class is same as the stack in previous assignment, just makes a stack to push and pop from
    It has a new member function called topCheck() ,which finds the top element of the stack and returns it

    The bracket matching is done using two functions; openBracketMatch() and closedBracketMatch()
    openBracketMatch() checks if a given character is one of (, [, { ,and if it is, pushes it to the stack
    closedBracketMatch() checks if a given character is one of ), ], } and if it matches the top of the stack,
    if it does then it pops the open bracket off the stack

    The third bracket function, isCloseBracket(), just checks that c is a closing bracket, that way
    we can return an error if there isnt a bracket on the stack to match with like in closedBracketMatch()

    For '//' we check if the first char is /, then use std::peak to see the next char
    If we are in a comment we keep incrementing through chars until we reach a new Line
    Then we start bracket checking again

    Strings of type "" and '' are treated much the same as above

    At the end, we check if the stack is empty; if it is then we pop each element off it and
    return an error saying what type of bracket is missing in the code.

    Flag variable works as a checkbit. Due to the design of my push,pop procedure, when a closing bracket was found
    without an opener on the stack the program while pointing out the error would still say "No errors found"
    Now if that error appears it switches flag from 0 to 1 to prevent the "No errors found" message

    If at the end, the stack is empty; Then there are no errors this code can detect in the file;
    So we return a "No errors in code" message

    Test5 is accounted for in that the opening brackets are counted and closed brackets are counted, so if
    they are not equal there are definite errors, however if they are identical and other errors are returned
    then it is quite likely the brackets are in the wrong order
************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX_STACK 10

bool openBracketMatch(char c);
bool isCloseBracket(char c);

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
  bool emptyCheck(void) ;
  bool fullCheck(void);
  char topCheck(void );
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
bool stack::emptyCheck(void) {
  if(top == 0){ //Stack is Empty
     return(true);
  }
  else{
     return(false);
  }
}
bool stack::fullCheck(void){
  if(top == (StackSize)){//stack is full
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
char stack::topCheck(void){//return the character on top of stack
    if(emptyCheck()){
      return((char)NULL);
    }
    else{
      return(contents[top-1]);
    }
}
bool closedBracketMatch(stack &syntaxChecker,char c);

int main(){
  stack syntaxChecker(5);

  std::ifstream InFile;
  //std::ofstream OutFile;
  char c;
  int flag = 0;//similar to a check bit
  int lineCount = 0;
  int pushCount = 0;
  int popCount = 0;

  std::string file;
  std::cout<< "Enter name of file to be checked: "<< std::endl;
  std::cin >> file;

  std::cout << "Processing the contents of " << file  << std::endl;
  InFile.open(file.c_str());


  while(! InFile.eof()){
    InFile.get(c);

    if(c == '\n'){
      lineCount++;
    }
    if(c == '/' && InFile.peek() == '/'){//Check if we're in a '//' style comment,skip on until '\n'
      while(c != '\n'){
        InFile.get(c);
      }
    }
    if(c == '/' && InFile.peek() == '*'){//same as above but for c-style comments
      InFile.get(c);
      InFile.get(c);
      while(c != '*' && InFile.peek() != '/'){
        InFile.get(c);
      }
    }
    if(c == ('\'')){ //same as above but for characters
      InFile.get(c);
      InFile.get(c);
    }
    if(c == ('\"')){//same as above but for strings
      InFile.get(c);
      while(c != '\"'){
        InFile.get(c);
      }
    }
    if(openBracketMatch(c)){//finds if a character is a opening bracket,if returns true then push character
      syntaxChecker.push(c);
      pushCount++;
    }
    if(isCloseBracket(c)){//finds if a character is a closing bracket,then check it matches top,then pop character
        popCount++;
        if(closedBracketMatch(syntaxChecker,c)){
          syntaxChecker.pop();
        }
        else{
          flag  = 1;
          std::cout << "Match of type " << c << " is needed" << std::endl;
        }
    }
  }
  InFile.close();

   std::cout << "Lines checked: " << lineCount << std::endl;

  //Show the amount of opening/closing brackets found/expected
  std::cout << "Brackets checked: " << pushCount;
  std::cout << " Brackets found: "<< popCount << std::endl;

  //If theres mo error then return a message saying this
  if(flag == 0 && syntaxChecker.emptyCheck()){
    std::cout << "No errors found" << std::endl;
  }
  //check if there is weighting issues in the brackets
  if(popCount != pushCount){
    std::cout << "Possible error(s) detected: see messages to identify" << std::endl;
    std::cout << "Error may also be caused by brackets entered in wrong order." << std::endl;
  }
  while(! syntaxChecker.emptyCheck()){//Empty the stack at the end of programme
    std::cout << "Bracket error detected,match for this bracket needed: ";
    std::cout << syntaxChecker.pop() << std::endl;
    popCount++;
  }
  return 0;
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
bool isCloseBracket(char c){
  if(c == ')'){
    return true;
  }
  if(c == ']'){
    return true;
  }
  if(c == '}'){
    return true;
  }
  else{
    return false;
  }
}
bool closedBracketMatch(stack &syntaxChecker ,char c){
  //std::cout << " c = "<< c << " " <<"top = " << syntaxChecker.topCheck() << std::endl;
  if((syntaxChecker.topCheck() == '(') && (c == ')')){
    return true;
  }
  if((syntaxChecker.topCheck() == '[') && (c == ']')){
    return true;
  }
  if((syntaxChecker.topCheck() == '{') && (c == '}')){
    return true;
  }
  else{
    return false;
  }
}
