#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int hammingDist(std::string a, std::string b)
{
  int dist = 0;
  for (int i = 0; i < a.length(); i++)
  {
    if (a[i] != b[i])
    {
      dist++;
    }
  }
  return dist;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // toss newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    int dictionarySize, testSize;
    std::cin >> dictionarySize >> testSize;

    // toss newline
    std::cin.ignore(1);

    std::vector<std::string> dictionary;

    for (int j = 0; j < dictionarySize; j++)
    {
      std::string word;
      std::getline(std::cin, word);
      dictionary.push_back(word);
    }

    // I *could* optimise this next bit by pre-sorting the dictionary by length and getting the first and last words of the same length, but I'm not going to bother
    // We have a whopping 2GB and 2 minutes to run, so I'm not going to worry about it
    for (int k = 0; k < testSize; k++)
    {
      std::string testWord;
      std::getline(std::cin, testWord);
      int leastDist = 1000000;
      std::string bestWord = "";
      for (std::string dictWord : dictionary)
      {
        // if length is different, skip
        if (dictWord.length() != testWord.length())
        {
          continue;
        }

        // otherwise, calculate hamming distance
        int dist = hammingDist(dictWord, testWord);
        if (dist < leastDist)
        {
          leastDist = dist;
          bestWord = dictWord;
        }
      }

      std::cout << bestWord << std::endl;
    }
  }
}