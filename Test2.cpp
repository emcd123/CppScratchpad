// Niall's Test Case 2: Checking if comments are handled correctly.
// Expected result: all OK
// Possible problem: braces in comments processed as code.

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <unistd.h>

// This would be an error if not in a comment (
/* This would be an error if not in a comment ] */

int main(void)
{
  std::cout << "Hello world \n" << std::endl;
  return 0;
}
