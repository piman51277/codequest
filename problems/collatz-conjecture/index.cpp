#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int collatzLength(int n)
{
  int length = 1;
  while (n != 1)
  {
    if (n % 2 == 0)
    {
      n = n / 2;
    }
    else
    {
      n = 3 * n + 1;
    }
    length++;
  }
  return length;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int n;
    std::cin >> n;
    std::cout << n << ":" << collatzLength(n) << std::endl;
  }
}