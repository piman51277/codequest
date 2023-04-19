#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;
  for (int i = 0; i < numTestCases; i++)
  {
    std::vector<std::string> lines;
    int lineCount;
    std::cin >> lineCount;

    // throw the newline
    std::cin.ignore(1);

    for (int k = 0; k < lineCount; k++)
    {
      std::string tmp;
      std::getline(std::cin, tmp);
      lines.push_back(tmp);
    }

    // figure out how long the longest line is
    int maxLen = 0;
    for (std::string k : lines)
    {
      maxLen = std::max(maxLen, (int)k.length());
    }

    // normalize all lines
    for (std::string k : lines)
    {
      k.insert(k.length(), maxLen - k.length(), ' ');
    }

    // the width will be (maxLen - 1)/2
    int width = (maxLen - 1) / 2 + 1;
    int height = lineCount;

    // compute prefix sums of rows
    std::vector<std::vector<int>> rowSums;
    for (int row = 0; row < height; row++)
    {
      std::vector<int> rowPrefix;
      rowPrefix.push_back(0);
      int last = 0;
      for (int pos = 1; pos < maxLen; pos += 2)
      {
        if (lines[row][pos] == '_')
        {
          last++;
          rowPrefix.push_back(last);
        }
        else
        {
          rowPrefix.push_back(last);
        }
      }

      rowSums.push_back(rowPrefix);
    }

    // same thing but for columns
    std::vector<std::vector<int>> colSums;
    for (int pos = 0; pos < maxLen; pos += 2)
    {
      std::vector<int> colPrefix;
      colPrefix.push_back(0);

      int last = 0;
      for (int row = 1; row < height; row++)
      {
        if (lines[row][pos] == '|')
        {
          last++;
          colPrefix.push_back(last);
        }
        else
        {
          colPrefix.push_back(last);
        }
      }

      colSums.push_back(colPrefix);
    }

    // start iterating over all positions
    int hitCount = 0;

    for (int x = 0; x < width -1; x++)
    {
      for (int y = 0; y < height-1; y++)
      {

        int maxSizeLength = std::min(width - x -1, height - y-1);

        for (int sideLen = 1; sideLen <= maxSizeLength; sideLen++)
        {

          // figure out how many edges are on the top edge
          int topEdges = rowSums[y][x + sideLen] - rowSums[y][x];

          // figure out how many edges are on the bottom edge
          int bottomEdges = rowSums[y + sideLen][x + sideLen] - rowSums[y + sideLen][x];

          // figure out how many edges are on the left edge
          int leftEdges = colSums[x][y + sideLen] - colSums[x][y];

          // right edge
          int rightEdges = colSums[x + sideLen][y + sideLen] - colSums[x + sideLen][y];

          bool edgesCorrect = topEdges == sideLen && bottomEdges == sideLen && leftEdges == sideLen && rightEdges == sideLen;
          if (edgesCorrect)
            hitCount++;
        }
      }
    }
    std::cout << hitCount << std::endl;
  }
}