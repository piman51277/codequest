#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // throw out the newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    // read in the line
    int speed;
    std::cin >> speed;

    // the next part is either "true" or "false"
    std::string isBirthday;
    std::cin >> isBirthday;

    bool isBirthdayBool = isBirthday == "true";

    int birthdayBoost = isBirthdayBool ? 5 : 0;
    int noTicketLimit = 60 + birthdayBoost;
    int smallLimit = 80 + birthdayBoost;

    if(speed <= noTicketLimit)
    {
      std::cout << "no ticket" << std::endl;
    }
    else if(speed <= smallLimit)
    {
      std::cout << "small ticket" << std::endl;
    }
    else
    {
      std::cout << "big ticket" << std::endl;
    }
  }
}