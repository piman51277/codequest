#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

double roundTenths(double n)
{
  return round(n * 10.0) / 10.0;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // set precision to 1
  std::cout << std::fixed;
  std::cout.precision(1);

  for (int i = 0; i < numTestCases; i++)
  {
    double num1, num2;
    char op;
    std::cin >> num1 >> op >> num2;

    switch (op)
    {
    case '+':
      std::cout << roundTenths(num1 + num2) << " " << roundTenths(num2 + num1) << std::endl;
      break;
    case '-':
      std::cout << roundTenths(num1 - num2) << " " << roundTenths(num2 - num1) << std::endl;
      break;
    case '*':
      std::cout << roundTenths(num1 * num2) << " " << roundTenths(num2 * num1) << std::endl;
      break;
    case '/':
      std::cout << roundTenths(num1 / num2) << " " << roundTenths(num2 / num1) << std::endl;
      break;
    default:

      break;
    }
  }
}