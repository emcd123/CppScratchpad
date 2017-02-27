// Niall's Test Case 4: missing brace
// Expected result: reports ']' on Line 16 not matched.

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

int main(void)
{
  int x[10];

  std::cout << "Hello world. This is Test Case 4: missing open square bracket"
	    << endl;
  std::cout << "x[8]=" << x8] << std::end;
  return(0);
}
