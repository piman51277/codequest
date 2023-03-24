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
    std::string isbn;
    std::cin >> isbn;

    std::vector<int> digits;
    for (char c : isbn)
    {
      if (c != 'X')
      {
        digits.push_back(c - '0');
      }
      else
      {
        digits.push_back(10);
      }
    }

    int sum = 0;
    for (int k = 0; k < 9; k++)
    {
      sum += digits[k] * (10 - k);
    }

    // this is stupid, but why not
    int diff = std::ceil(sum / 11.0) * 11 - sum;

    if (diff == digits[9])
    {
      std::cout << "VALID" << std::endl;
    }
    else
    {
      std::cout << "INVALID" << std::endl;
    }
  }
}