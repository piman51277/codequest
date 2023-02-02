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
    int y;
    std::cin >> y;

    // compute the mess that is this formula
    int a = y % 19;
    int b = y % 4;
    int c = y % 7;
    int k = floor(y / 100);
    int p = floor((13 + 8 * k) / 25);
    int q = floor(k / 4);
    int m = (15 - p + k - q) % 30;
    int n = (4 + k - q) % 7;
    int d = (19 * a + m) % 30;
    int e = (2 * b + 4 * c + 6 * d + n) % 7;
    int f = (11 * m + 11) % 30;

    int date = 22 + d + e;
    int month = 0;
    if (date <= 31)
    {
      month = 3;
    }
    else
    {
      month = 4;
      date -= 31;
    }

    if (month == 4 && date == 25 && d == 28 && e == 6 && f < 19)
    {
      date = 18;
    }

    if (month == 4 && date == 26 && d == 29 && e == 6)
    {
      date = 19;
    }

    std::cout << y << "/";

    //add month, pad with 0
    if (month < 10)
    {
      std::cout << "0";
    }
    std::cout << month << "/";

    //add date, pad with 0
    if (date < 10)
    {
      std::cout << "0";
    }
    std::cout << date << std::endl;
  }
}