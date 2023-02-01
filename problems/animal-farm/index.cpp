#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0;i<numTestCases;i++)
  {
    int turkeys, goats, horses;
    std::cin >> turkeys >> goats >> horses;

    int totalLegs = turkeys * 2 + (goats + horses) * 4;
    std::cout << totalLegs << std::endl;
  }
}