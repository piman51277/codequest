#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  //dump one char
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    // read in the $ amount
    std::string money;
    std::getline(std::cin, money);
    std::cout << money << std::endl;

    //remove the $ and .
    money.erase(0, 1);
    money.erase(money.find("."), 1);

    //convert to int
    float cents = std::stoi(money);

    //compute the change
    int quarters = floor(cents / 25);
    cents -= quarters * 25;

    int dimes = floor(cents / 10);
    cents -= dimes * 10;

    int nickels = floor(cents / 5);
    cents -= nickels * 5;

    int pennies = cents;

    //output the change
    std::cout << "Quarters=" << quarters << std::endl;
    std::cout << "Dimes=" << dimes << std::endl;
    std::cout << "Nickels=" << nickels << std::endl;
    std::cout << "Pennies=" << pennies << std::endl;

  }
}