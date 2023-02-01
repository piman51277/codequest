#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

bool isAnagram(std::string first, std::string second)
{
  // if the strings are the same, they are not
  if (first == second)
    return false;

  // otherwise, sort the strings and compare
  std::sort(first.begin(), first.end());
  std::sort(second.begin(), second.end());

  for (int i = 0; i < first.length(); i++)
  {
    if (first[i] != second[i])
      return false;
  }
  return true;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // take out the newline character
  std::cin.ignore(1);

  // per case
  for (int i = 0; i < numTestCases; i++)
  {
    std::string rawInput;
    std::getline(std::cin, rawInput);

    // split the string into two, breaking on the | char
    int splitIndex = rawInput.find('|');
    std::string first = rawInput.substr(0, splitIndex);
    std::string second = rawInput.substr(splitIndex + 1, rawInput.length());

    bool isCaseAnagram = isAnagram(first, second);

    std::cout << rawInput << " = " << (isCaseAnagram ? "" : "NOT AN ") << "ANAGRAM" << std::endl;
  }
}