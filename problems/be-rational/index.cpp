#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cmath>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    std::string initialString;
    std::getline(std::cin, initialString);

    std::vector<long long> terms;

    // split the string on the decimal
    int decIndex = initialString.find_first_of('.');
    std::string head = initialString.substr(0, decIndex);
    std::string tail = initialString.substr(decIndex + 1, initialString.length() - 1);

    terms.push_back(std::stoi(head));

    long long numer = std::stoll(tail);
    long long demon = std::pow(10, tail.length());
    for (int k = 1; k < 10; k++)
    {
      // flip and see mix int
      int mixInt = std::floor(demon / numer);

      terms.push_back(mixInt);

      // get remainder
      long long remain = demon % numer;

      // if this is 0, end it;
      if (remain == 0)
        break;

      demon = numer;
      numer = remain;
    }

    // print out the terms
    std::string out;
    for (int k : terms)
    {
      out += std::to_string(k) + ' ';
    }
    out.pop_back();

    std::cout << out << std::endl;
  }
}