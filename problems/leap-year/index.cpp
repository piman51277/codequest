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
    int subcases;
    std::cin >> subcases;

    for (int j = 0; j < subcases; j++)
    {
      int year;
      std::cin >> year;

      //if year is before 1582, it is not a leap year
      if (year < 1582)
      {
        std::cout << "No" << std::endl;
        continue;
      }

      if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        std::cout << "Yes" << std::endl;
      else
        std::cout << "No" << std::endl;
    }
  }
}