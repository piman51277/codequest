#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

bool handleCase(int fillerBricks, int fiveBricks, int targetLength)
{
  // first figure out if we can make the target length at all
  int totalBricks = fillerBricks + fiveBricks * 5;

  if (totalBricks < targetLength)
  {
    return false;
  }

  // now figure out if we can actually make the target length
  int fiveBricksUsed = std::min(targetLength / 5, fiveBricks);
  int fillerBricksNeeded = targetLength - fiveBricksUsed * 5;

  if (fillerBricksNeeded > fillerBricks)
  {
    return false;
  }

  return true;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int fillerBricks, fiveBricks, targetLength;
    std::cin >> fillerBricks >> fiveBricks >> targetLength;

    if (handleCase(fillerBricks, fiveBricks, targetLength))
    {
      std::cout << "true" << std::endl;
    }
    else
    {
      std::cout << "false" << std::endl;
    }
  }
}