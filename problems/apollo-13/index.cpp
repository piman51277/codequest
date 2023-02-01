#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  //set floating point decimal precision
  std::cout << std::fixed;
  std::cout.precision(2);


  for (int i = 0; i < numTestCases; i++)
  {
    std::vector<double> gimbals = {};
    for(int k = 0; k < 3; k++)
    {
      double gimbal;
      std::cin >> gimbal;

      gimbal -= 180;
      gimbal = gimbal > 0 ? gimbal : 360 + gimbal;

      gimbals.push_back(gimbal);
    }

    std::cout << std::setfill('0') << std::setw(6) << gimbals[0] << " ";
    std::cout << std::setfill('0') << std::setw(6) << gimbals[1] << " ";
    std::cout << std::setfill('0') << std::setw(6) << gimbals[2] << std::endl;
  }
}