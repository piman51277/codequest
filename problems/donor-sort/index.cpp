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

//God I miss JS pt.2
std::string join(std::vector<std::string> vec, char delimiter)
{
  std::string str = "";
  for (int i = 0; i < vec.size(); i++)
  {
    str += vec[i];
    if (i != vec.size() - 1)
    {
      str += delimiter;
    }
  }
  return str;
}


int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  //ditch the newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    //get the previous year
    std::string lastYearDonors;
    std::getline(std::cin, lastYearDonors);

    //get the current year
    std::string currentYearDonors;
    std::getline(std::cin, currentYearDonors);

    //split the strings into vectors
    std::vector<std::string> lastYearDonorsVector = split(lastYearDonors, ',');
    std::vector<std::string> currentYearDonorsVector = split(currentYearDonors, ',');

    //figure out donors in both
    std::vector<std::string> donorsInBoth;
    for(std::string i: lastYearDonorsVector)
    {
      for(std::string j: currentYearDonorsVector)
      {
        if(i == j)
        {
          donorsInBoth.push_back(i);
        }
      }
    }

    //figure out donors in last year but not current year
    std::vector<std::string> donorsLastYearOnly;
    for(std::string i: lastYearDonorsVector)
    {
      bool isDonorInBoth = false;
      for(std::string j: donorsInBoth)
      {
        if(i == j)
        {
          isDonorInBoth = true;
          break;
        }
      }
      if(!isDonorInBoth)
      {
        donorsLastYearOnly.push_back(i);
      }
    }

    //figure out donors in current year but not last year
    std::vector<std::string> donorsCurrentYearOnly;
    for(std::string i: currentYearDonorsVector)
    {
      bool isDonorInBoth = false;
      for(std::string j: donorsInBoth)
      {
        if(i == j)
        {
          isDonorInBoth = true;
          break;
        }
      }
      if(!isDonorInBoth)
      {
        donorsCurrentYearOnly.push_back(i);
      }
    }

    //sort the vectors alphabetically
    std::sort(donorsInBoth.begin(), donorsInBoth.end());
    std::sort(donorsLastYearOnly.begin(), donorsLastYearOnly.end());
    std::sort(donorsCurrentYearOnly.begin(), donorsCurrentYearOnly.end());

    std::cout << join(donorsLastYearOnly, ',') << std::endl;
    std::cout << join(donorsInBoth, ',') << std::endl;
    std::cout << join(donorsCurrentYearOnly, ',') << std::endl;
  }
}
