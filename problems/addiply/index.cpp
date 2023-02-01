#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // handle test cases
  for (int i = 0; i < numTestCases; i++)
  {
    int num1, num2;
    std::cin >> num1 >> num2;
    int sum = num1 + num2;
    int product = num1 * num2;
    std::cout << sum << " " << product << std::endl;
  }
}