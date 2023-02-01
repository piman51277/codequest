#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>

std::vector<std::string> split(std::string str, char delimiter)
{
  std::vector<std::string> internal;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;

  while (getline(ss, tok, delimiter))
  {
    internal.push_back(tok);
  }

  return internal;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // dump one char
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    // get next line
    std::string line;
    std::getline(std::cin, line);

    // split line by ,
    std::vector<std::string> splitLine = split(line, ',');

    // convert to int
    std::vector<int> nums;
    for (std::string num : splitLine)
    {
      nums.push_back(std::stoi(num));
    }

    // sort low->high
    std::sort(nums.begin(), nums.end());

    // print with comma delim
    for (int i = 0; i < nums.size(); i++)
    {
      std::cout << nums[i];
      if (i != nums.size() - 1)
      {
        std::cout << ",";
      }
    }

    std::cout << std::endl;
  }
}