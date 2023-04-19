#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    std::string input;
    std::getline(std::cin, input);
    for (int pos = input.length() - 1; pos >= 0; pos--){
      std::cout << input[pos];
    }
    std::cout << std::endl;
  }
}