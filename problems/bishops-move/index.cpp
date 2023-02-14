#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int squareColor(int x, int y)
{
  if ((x + y) % 2 == 0)
    return 0;
  else
    return 1;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    char dump;
    int bx, by, sx, sy, ex, ey;
    std::cin >> bx >> dump >> by >> sx >> dump >> sy >> ex >> dump >> ey;

    // check if sx,sy is within the board
    if (sx < 1 || sx > bx || sy < 1 || sy > by)
    {
      std::cout << "No" << std::endl;
      continue;
    }

    // check if ex,ey is within the board
    if (ex < 1 || ex > bx || ey < 1 || ey > by)
    {
      std::cout << "No" << std::endl;
      continue;
    }

    // check if sx,sy and ex,ey is on the same color
    if (squareColor(sx, sy) != squareColor(ex, ey))
    {
      std::cout << "No" << std::endl;
      continue;
    }

    std::cout << "Yes" << std::endl;
  }
}