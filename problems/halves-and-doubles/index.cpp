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
    long long a, b;
    std::cin >> a >> b;

    long long actualProduct = 0;

    bool remainderFlag = false;

    while (true)
    {

      // write out the first in the pair
      std::cout << a;

      if (remainderFlag)
      {
        std::cout << "*";
      }

      std::cout << " ";

      std::cout << b;

      // if the first number is even, then add the bars
      if (a % 2 == 0)
      {
        std::cout << " ***";
      }
      else
      {
        actualProduct += b;
      }

      std::cout << std::endl;
      if (a == 1)
      {
        std::cout << actualProduct << std::endl;
        break;
      }

      // make the next pair

      remainderFlag = false;
      if (a % 2 == 1)
      {
        remainderFlag = true;
      }
      a = a / 2;

      b = b * 2;
    }
  }
}