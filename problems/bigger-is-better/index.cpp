#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  //throw away the newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    std::string input;
    std::getline(std::cin, input);

    //convert into a string stream
    std::stringstream ss(input);
    std::string strint;

    long long max = -10000;

    while(std::getline(ss, strint, ' '))
    {
      long long num = std::stoll(strint);
      if (num > max)
      {
        max = num;
      }
    }

    std::cout << max << std::endl;
  }
}