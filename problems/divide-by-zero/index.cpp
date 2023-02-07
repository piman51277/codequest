#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <sstream>

//stolen from SO
bool isFloat(std::string s)
{
  std::istringstream iss(s);
  float dummy;
  iss >> std::noskipws >> dummy;
  return iss && iss.eof(); // Result converted to bool
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  //toss out the rest of the line
  std::cin.ignore(1);

  std::cout << std::fixed;
  std::cout.precision(1);

  for (int i = 0; i < numTestCases; i++)
  {
    //read in the line
    std::string line;
    std::getline(std::cin, line);

    //split by " "
    std::string first, second;
    first = line.substr(0, line.find(" "));
    second = line.substr(line.find(" ") + 1);

    //check if we can convert to int
    float firstInt, secondInt;

    if(isFloat(first)){
      firstInt = std::stof(first);
    }
    else{
      std::cout << "Invalid Dividend" << std::endl;
      continue;
    }

    if(isFloat(second)){
      secondInt = std::stof(second);
    }
    else{
      std::cout << "Invalid Divisor" << std::endl;
      continue;
    }

    //check if it's a div0 with epsilon of 0.0001
    if (std::abs(secondInt) < 0.0001)
    {
      std::cout << "Divide By Zero" << std::endl;
      continue;
    }

    //do the division
    float result = (float)firstInt / (float)secondInt;

    //round to 1 decimal place
    result = std::round(result * 10) / 10;

    std::cout << result << std::endl;
  }
}