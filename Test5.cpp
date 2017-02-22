// Niall's Test Case 5: mis-ordered  braces
// Expected result: reports ')' on Line 11 not matched.
// Possible problem: only checking if the number of left braces
//    matches the number of right braces.
#include <iostream>

int main(void)
{
  int x[10];

  cout << "Test Case 5 (misordered braces)" << endl;
  cout << "x[8]=" << (x[8)] << end;
  return (0);  
}
