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

  // prepare an array of fibonacci numbers
  std::vector<long long> fib(2);
  fib[0] = 0;
  fib[1] = 1;
  int maxCalculated = 1;
  long long maxFib = 1;

  for (int i = 0; i < numTestCases; i++)
  {
    int k;
    std::cin >> k;

    // if k is less than the max calculated, look for it in the array
    if (k <= maxCalculated)
    {
      bool isFib = std::find(fib.begin(), fib.end(), k) != fib.end();
      if (isFib)
        std::cout << "TRUE" << std::endl;
      else
        std::cout << "FALSE" << std::endl;
      continue;
    }

    // if k is greater than the max calculated, calculate more until we reach k or go past it
    while (k > maxCalculated && maxCalculated < 90)
    {
      maxCalculated++;
      fib.push_back(fib[maxCalculated - 1] + fib[maxCalculated - 2]);
      maxFib = fib[maxCalculated];
    }

    // check if k is in the array
    bool isFib = std::find(fib.begin(), fib.end(), k) != fib.end();
    if (isFib)
      std::cout << "TRUE" << std::endl;
    else
      std::cout << "FALSE" << std::endl;
  }
}