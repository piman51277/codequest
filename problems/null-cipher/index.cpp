#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  //throw away the newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    std::string line;
    std::getline(std::cin, line);

    std::string message;
    for (int j = 0; j < line.length(); j++)
    {
      char c = line[j];

      //if c is a vowel, add the following letter
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      {
        message += line[j + 1];
        j++;
      }
    }

    std::cout << message << std::endl;
  }
}