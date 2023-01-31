#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

int main()
{
  int testCases = 0;
  std::cin >> testCases;

  for (int i = 0; i < testCases; i++)
  {

    // read in the two floats
    float velocity, distance;
    char colon;
    std::cin >> velocity >> colon >> distance;

    // compute time to impact
    float time = distance / velocity;

    if (time <= 1.0)
    {
      std::cout << "SWERVE" << std::endl;
    }
    else if (time <= 5.0)
    {
      std::cout << "BRAKE" << std::endl;
    }
    else
    {
      std::cout << "SAFE" << std::endl;
    }
  }
}