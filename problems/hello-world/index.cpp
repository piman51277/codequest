#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // get rid of the newline character
  std::cin.ignore(1);

  // handle test cases
  for (int i = 0; i < numTestCases; i++)
  {
    std::string caseString;
    std::getline(std::cin, caseString);
    std::cout << caseString << std::endl;
  }
}