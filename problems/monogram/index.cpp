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

  for (int i = 0; i < numTestCases; i++)
  {

    int numNames;
    std::cin >> numNames;

    // ditch the newline
    std::cin.ignore(1);

    for (int j = 0; j < numNames; j++)
    {
      std::string name;
      std::getline(std::cin, name);

      // set to upper case
        std::transform(name.begin(), name.end(), name.begin(), ::toupper);

      std::vector<std::string> nameVector = split(name, ' ');

      std::cout << nameVector[0][0] << nameVector[2][0] << nameVector[1][0] << std::endl;
    }
  }
}
