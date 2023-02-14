#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

bool checkPwd(std::string pwd)
{
  if (pwd.length() < 8)
  {
    return false;
  }

  bool hasUpper = false;
  bool hasLower = false;
  bool hasDigit = false;
  bool hasSpecial = false;

  for (char c : pwd)
  {

    if (isupper(c))
    {
      hasUpper = true;
    }
    else if (islower(c))
    {
      hasLower = true;
    }
    else if (isdigit(c))
    {
      hasDigit = true;
    }
    else
    {
      hasSpecial = true;
    }
  }

  bool hasGroups = ((int)hasUpper) + ((int)hasLower) + ((int)hasDigit) + ((int)hasSpecial) >= 3;

  if (!hasGroups)
  {
    return false;
  }

  for (int i = 0; i < pwd.length() - 2; i++)
  {
    char c = pwd[i];
    char c2 = pwd[i + 1];
    char c3 = pwd[i + 2];
    if (c == c2 && c2 == c3)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // throw newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    std::string testPwd;
    std::getline(std::cin, testPwd);

    bool isValid = checkPwd(testPwd);

    if (isValid)
    {
      std::cout << "VALID" << std::endl;
    }
    else
    {
      std::cout << "INVALID" << std::endl;
    }
  }
}