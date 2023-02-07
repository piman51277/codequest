#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{

  // This is always 1 for this problem
  int numTestCases = 0;
  std::cin >> numTestCases;

  int numUpperLines = 0;
  std::cin >> numUpperLines;

  std::vector<int> upperLineLengths;
  for (int i = 0; i < numUpperLines; i++)
  {
    int length = 0;
    std::cin >> length;
    upperLineLengths.push_back(length);
  }

  int numLowerLines = 0;
  std::cin >> numLowerLines;

  std::vector<int> lowerLineLengths;
  for (int i = 0; i < numLowerLines; i++)
  {
    int length = 0;
    std::cin >> length;
    lowerLineLengths.push_back(length);
  }

  std::cin.ignore(1);
  std::vector<std::string> lines;

  while (!std::cin.eof())
  {
    std::string line;
    std::getline(std::cin, line);
    lines.push_back(line);
  }

  // now sort them into upper and lower
  std::string upperChars;
  std::string lowerChars;

  for (std::string line : lines)
  {
    for (char c : line)
    {
      if ((c >= 'A' && c <= 'Z') || c == '-')
      {
        if (c != '-')
        {
          upperChars.push_back(c);
        }
        else
        {
          upperChars.push_back(' ');
        }
      }
      else if ((c >= 'a' && c <= 'z') || c == '=')
      {
        if (c != '=')
        {
          lowerChars.push_back(c);
        }
        else
        {
          lowerChars.push_back(' ');
        }
      }
    }
  }


  // read out the upper lines
  int upperIndex = 0;
  for (int length : upperLineLengths)
  {
    std::string line = upperChars.substr(upperIndex, length);
    std::cout << line << std::endl;
    upperIndex += length;
  }

  // single newline
  std::cout << std::endl;

  // read out the lower lines
  int lowerIndex = 0;
  for (int length : lowerLineLengths)
  {
    std::string line = lowerChars.substr(lowerIndex, length);
    std::cout << line << std::endl;
    lowerIndex += length;
  }
}