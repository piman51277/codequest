#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <bitset>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // throw the newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    // read in the str
    std::string str;
    std::getline(std::cin, str);

    std::bitset<7> working;
    for (int j = 0; j < str.length(); j++)
    {
      // read in 7 chars and convert to binary
      int pos = j % 7;
      if (str[j] == 'A' || str[j] == 'T')
      {
        working.set(6 - pos, false);
      }
      else
      {
        working.set(6 - pos, true);
      }

      // if we have just done 7 chars, print the binary
      if (pos == 6)
      {
        // convert to a char
        char c = (char)working.to_ulong();
        std::cout << c;

        // reset the working bitset
        working.reset();
      }
    }
    std::cout << std::endl;
  }
}