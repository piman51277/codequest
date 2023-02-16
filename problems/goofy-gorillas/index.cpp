#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    std::string first, second;
    std::cin >> first >> second;
    if(first == second){
      std::cout << "true" << std::endl;
    } else {
      std::cout << "false" << std::endl;
    }
  }
}