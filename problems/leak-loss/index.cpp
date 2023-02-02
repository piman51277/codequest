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
    double volume, fillRate, drainRate;
    std::cin >> volume >> fillRate >> drainRate;

    double netRate = fillRate - drainRate;
    double fillTime = volume / netRate;
    double leaked = fillTime * drainRate;

    //round to nearest integer
    int out = round(leaked);

    std::cout << out << std::endl;
  }
}