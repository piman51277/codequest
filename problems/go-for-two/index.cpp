#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // this is kindof dumb but honestly I don't care
  std::vector<int> conversion2{-15, -13, -11, -10, -8, -5, -4, -2, 1, 5, 12};

  for (int i = 0; i < numTestCases; i++)
  {
    int us, them;
    std::cin >> us >> them;

    int delta = us - them;

    // if the delta is in conversion 2
    if (std::find(conversion2.begin(), conversion2.end(), delta) != conversion2.end())
    {
      std::cout << "2" << std::endl;
    }
    else
    {
      std::cout << "1" << std::endl;
    }
  }
}