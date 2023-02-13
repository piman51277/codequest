#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // toss the rest of the line
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    std::string line;
    std::getline(std::cin, line);

    int score = 0;
    for (char k : line)
    {
      score += k - 'a' + 1;
    }

    std::cout << score << std::endl;
  }
}