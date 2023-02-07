#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  //throw away the newline
  std::cin.ignore(1);

  int denominations[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 25, 10, 5, 1};

  for (int i = 0; i < numTestCases; i++)
  {
    //this is money, we have to read it as ints
    std::string raw;
    std::getline(std::cin, raw);

    int dollars, cents;
    int pos = raw.find('.');
    dollars = std::stoi(raw.substr(0, pos));
    cents = std::stoi(raw.substr(pos + 1)) + dollars * 100;

    for(int deno: denominations)
    {
      int num = cents / deno;
      cents -= num * deno;
      std::cout << num;
    }
    std::cout << std::endl;


  }
}