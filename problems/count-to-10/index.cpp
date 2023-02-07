#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <bitset>

std::string toBinary(int num, int maxLength){
  //use bitset to convert to binary
  std::bitset<32> b(num);

  //convert to string
  std::string s = b.to_string();

  //remove leading zeros
  std::string r = s.substr(32-maxLength);

  return r;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int max;
    std::cin >> max;

    int maxVal = std::pow(2, max) - 1;

    for (int k = 0; k <= maxVal; k++)
    {
      std::string binary = toBinary(k, max);
      std::cout << binary << std::endl;
    }
  }
}