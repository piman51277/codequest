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

  // set precision to 3
  std::cout << std::fixed;
  std::cout << std::setprecision(3);

  for (int i = 0; i < numTestCases; i++)
  {
    // get line
    std::string line;
    std::getline(std::cin, line);

    // split line by :
    std::vector<std::string> splitLine = split(line, ':');

    std::string name = splitLine[0];
    std::vector<std::string> bats = split(splitLine[1], ',');

    int score = 0;
    int count = 0;
    for (std::string type : bats)
    {
      if (type == "BB")
      {
        continue;
      }

      count++;
      if (type == "1B")
      {
        score++;
      }
      else if (type == "2B")
      {
        score += 2;
      }
      else if (type == "3B")
      {
        score += 3;
      }
      else if (type == "HR")
      {
        score += 4;
      }
    }

    double slg = count != 0 ? (double)score / (double)count : 0;

    std::cout << name << "=" << slg << std::endl;
  }
}