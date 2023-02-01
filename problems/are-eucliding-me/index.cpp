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
    int n, m = 0;
    char dump;
    std::cin >> n >> dump >> m;

    int minuend = std::max(n, m);
    int subtrahend = std::min(n, m);
    while (true)
    {
      int difference = minuend - subtrahend;

      // print the equation
      std::cout << minuend << "-" << subtrahend << "=" << difference << std::endl;

      // check if we're done
      if (difference == 0)
      {
        // if the two operands are 1
        if (minuend == 1)
        {
          std::cout << "COPRIME" << std::endl;
        }
        else
        {
          std::cout << "NOT COPRIME" << std::endl;
        }
        break;
      }

      // update the minuend and subtrahend
      minuend = std::max(difference, subtrahend);
      subtrahend = std::min(difference, subtrahend);
    }
  }
}