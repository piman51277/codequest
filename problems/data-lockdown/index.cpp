#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // toss the newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    int sites;
    std::cin >> sites;

    std::cin.ignore(1);

    for (int j = 0; j < sites; j++)
    {
      // read in the line
      std::string line;
      std::getline(std::cin, line);

      // split the line into two strings by the space
      int spaceIndex = line.find(' ');
      std::string url = line.substr(0, spaceIndex);
      int size = std::stoi(line.substr(spaceIndex + 1));

      // the url must end with ".lmco.com"
      bool hasCorrectSuffix = url.size() >= 9 && url.substr(url.size() - 9) == ".lmco.com";

      if(!hasCorrectSuffix && size >1000){
        std::cout << line << std::endl;
      }
    }
  }
}