#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <math.h>

float roundPrec(float num, int prec)
{
  float factor = pow(10.0, prec);
  return round(num * factor) / factor;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // set fixed and precision to 1
  std::cout << std::fixed;
  std::cout.precision(1);

  for (int i = 0; i < numTestCases; i++)
  {
    int altitude = 0;
    std::cin >> altitude;

    // this formula comes from an interesting mathematical riddle I once saw
    // If I have a string wrapped tightly around the Earth, and I decide to lift the string 1 meter in the air, how much longer will the string be?
    // The answer is 2*pi meters, or 6.28 meters.
    // So, if I lift the string k meters in the air, how much longer will the string be?
    // The answer is 2*pi*k meters, or 6.28*k meters.

    double delta = 2 * M_PI * altitude;
    double distance = 40075.0 + delta;

    std::cout << distance << "\n";
  }
}