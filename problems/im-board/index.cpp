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
    int sideLen = 0;
    std::cin >> sideLen;

    for (int row = 0; row < sideLen; row++)
    {
      std::string k = "";
      for (int col = 0; col < sideLen; col++)
      {
        k += "# ";
      }
      k.pop_back();
      std::cout << k << std::endl;
    }
  }
}