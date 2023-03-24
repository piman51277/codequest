#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>

std::vector<std::string> ICAO = {
    "Alpha",
    "Bravo",
    "Charlie",
    "Delta",
    "Echo",
    "Foxtrot",
    "Golf",
    "Hotel",
    "India",
    "Juliet",
    "Kilo",
    "Lima",
    "Mike",
    "November",
    "Oscar",
    "Papa",
    "Quebec",
    "Romeo",
    "Sierra",
    "Tango",
    "Uniform",
    "Victor",
    "Whiskey",
    "Xray",
    "Yankee",
    "Zulu"};

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
    int lineCount = 0;
    std::cin >> lineCount;
    std::cin.ignore(1);

    std::vector<std::string> lines;
    for (int j = 0; j < lineCount; j++)
    {
      std::string line;
      std::getline(std::cin, line);
      lines.push_back(line);
    }

    for (std::string line : lines)
    {
      std::vector<std::string> ICAOWords = {};
      std::vector<std::string> words = split(line, ' ');
      for (std::string word : words)
      {
        std::vector<std::string> ICAOWord = {};
        for (char c : word)
        {
          c = std::toupper(c);
          ICAOWord.push_back(ICAO[c - 'A']);
        }

        // join the ICAO word with dashes
        std::string ICAOWordStr = "";
        for (std::string s : ICAOWord)
        {
          ICAOWordStr += s + "-";
        }
        ICAOWordStr.pop_back();

        ICAOWords.push_back(ICAOWordStr);
      }

      // join the ICAO words with spaces
      std::string ICAOWordsStr = "";
      for (std::string s : ICAOWords)
      {
        ICAOWordsStr += s + " ";
      }
      ICAOWordsStr.pop_back();

      std::cout << ICAOWordsStr << std::endl;
    }
  }
}