// Niall's Test Case 3: braces in quotes.
// Expected result: all OK
// Possible problem: braces in single or double quotes treated literally

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <unistd.h>

int main(void)
{
  std::cout << "Hello world, here is a brace: ( " << std::endl;
  std::cout << "Hello again, here is another brace: " << ']' << std::endl;
  return(0);
}
