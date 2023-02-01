#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // the max k is 90. Therefore, prepare an array of 90 elements
  std::vector<long long> fib(90);
  fib[0] = 0;
  fib[1] = 1;

  int maxCalculated = 1;

  for (int i = 0; i < numTestCases; i++)
  {
    int k;
    std::cin >> k;

    // k counts from 1, but the array counts from 0
    k--;

    // have we already calculated the kth fibonacci number?
    if (k > maxCalculated)
    {
      // no, so calculate it
      for (int j = maxCalculated + 1; j <= k; j++)
      {
        fib[j] = fib[j - 1] + fib[j - 2];
      }

      maxCalculated = k;
    }

    std::cout << k + 1 << " = " << fib[k] << std::endl;
  }
}