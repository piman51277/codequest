#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>

//this is better than the suggested solutions!
//Time: O(n)
//Space: O(1)
int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int n;
    std::cin >> n;

    //throw away the newline
    std::cin.ignore(1);

    std::string input;
    std::getline(std::cin, input);

    //convert into a string stream
    std::stringstream ss(input);
    std::string strint;

    //compute the num of the first N integers
    int sum = (n * (n + 1)) / 2;

    while(std::getline(ss, strint, ' '))
    {
      int num = std::stoi(strint);
      sum -= num;
    }

    std::cout << sum << std::endl;
  }
}