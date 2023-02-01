#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cctype>

// this mutates in-place
void stringLower(std::string &str)
{
  for (int i = 0; i < str.length(); i++)
  {
    str[i] = std::tolower(str[i]);
  }
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // dump the newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    // get the next line
    std::string line;
    std::getline(std::cin, line);

    // split the line into 2 sections, delim |
    int delimPos = line.find('|');
    std::string left = line.substr(0, delimPos);
    std::string right = line.substr(delimPos + 1);

    // make the left and right strings lowercase
    stringLower(left);
    stringLower(right);

    // we have plenty of memory, so we can just use a bool array here
    bool letters[26];
    std::fill_n(letters, 26, false);

    // iterate over the left string and mark the letters we see
    for (char ch : left)
    {
      // check if the char is a lowercase letter
      // FIXME: This assumes ASCII / UTF-8!
      if (ch >= 'a' && ch <= 'z')
      {
        // mark the letter as seen
        letters[ch - 'a'] = true;
      }
    }

    // iterate over the right string and check if we've seen the letters
    bool isContact = true;
    for (char ch : right)
    {
      // check if the char is a lowercase letter
      if (ch >= 'a' && ch <= 'z' && !letters[ch - 'a'])
      {
        // we haven't seen this letter, so it's not a contact
        isContact = false;
        break;
      }
    }

    if (isContact)
    {
      std::cout << "That's my secret contact!" << std::endl;
    }
    else
    {
      std::cout << "You're not a secret agent!" << std::endl;
    }
  }
}