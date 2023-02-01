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
    int n;
    std::cin >> n;

    long long factorial = 1;
    for (int j = 1; j <= n; j++)
    {
      factorial *= j;
    }

    std::cout << factorial << std::endl;
  }
}