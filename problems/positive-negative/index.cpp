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
    int k;
    std::cin >> k;

    if(k > 0){
      std::cout << "POSITIVE" << std::endl;
    }
    else if(k < 0){
      std::cout << "NEGATIVE" << std::endl;
    }
  }
}