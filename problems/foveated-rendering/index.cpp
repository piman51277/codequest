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
    int width = 0;
    int height = 0;
    std::cin >> width >> height;
    std::pair<int, int> testCase = std::make_pair(width, height);

    std::vector<std::vector<int>> rows;
    for (int i = 0; i < 20; i++)
    {
      std::vector<int> row;
      for (int j = 0; j < 20; j++)
      {

        // if this IS a test case, output 100
        if (i == testCase.first && j == testCase.second)
        {
          row.push_back(100);
          continue;
        }

        // check if we are in +- 1 x and y from a test case
        if (abs(i - testCase.first) <= 1 && abs(j - testCase.second) <= 1)
        {
          row.push_back(50);
          continue;
        }

        // check if we are in +- 2 x and y from a test case
        if (abs(i - testCase.first) <= 2 && abs(j - testCase.second) <= 2)
        {
          row.push_back(25);
          continue;
        }

        // otherwise it's 10
        row.push_back(10);
      }
      rows.push_back(row);
    }

    // print out the rows
    for (int i = 0; i < rows.size(); i++)
    {
      for (int j = 0; j < rows[i].size() - 1; j++)
      {
        std::cout << rows[i][j] << " ";
      }
      std::cout << rows[i][rows[i].size() - 1];
      std::cout << std::endl;
    }
  }
}