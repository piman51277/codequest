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

char caesar(char c, int offset, bool direction)
{
  if (!direction)
  {
    int val = ((c - 'A') + offset) % 26;
    if (val < 0)
      val += 26;
    return val + 'A';
  }
  else
  {

    int val = ((c - 'A') - offset) % 26;
    if (val < 0)
      val += 26;
    return val + 'A';
  }
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // throw out the neline char
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    std::string ciphertext;
    std::getline(std::cin, ciphertext);

    std::vector<int> offsets;
    std::vector<bool> directions;

    // take in the list of offsets
    std::string offsetString;
    std::getline(std::cin, offsetString);
    std::vector<std::string> offsetStrings = split(offsetString, ' ');
    for (int i = 0; i < offsetStrings.size(); i++)
    {
      offsets.push_back(std::stoi(offsetStrings[i]));
    }

    // take in the list of directions
    std::string directionString;
    std::getline(std::cin, directionString);
    std::vector<std::string> directionStrings = split(directionString, ' ');
    for (int i = 0; i < directionStrings.size(); i++)
    {
      if (directionStrings[i] == "0")
      {
        directions.push_back(false);
      }
      else
      {
        directions.push_back(true);
      }
    }

    // decode
    std::string plaintext = "";

    int offsetIndex = 0;
    int pairIndex = 0;
    for (int i = 0; i < ciphertext.size(); i++)
    {
      // check if the char is a letter
      if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
      {
        plaintext += std::tolower(caesar(ciphertext[i], offsets[offsetIndex], directions[pairIndex]));
        offsetIndex = (offsetIndex + 1) % offsets.size();
        pairIndex = (pairIndex + 1) % directions.size();
      }
      else
      {
        plaintext += ciphertext[i];
      }
    }

    std::cout << plaintext << std::endl;
  }
}
