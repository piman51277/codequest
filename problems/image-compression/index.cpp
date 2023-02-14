#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int values;
    std::cin >> values;

    std::vector<float> v;

    for (int j = 0; j < values; j++)
    {
      float value;
      std::cin >> value;
      v.push_back(value);
    }

    float min = *std::min_element(v.begin(), v.end());
    float max = *std::max_element(v.begin(), v.end());

    for (float k : v)
    {
      std::cout << round((k - min) / (max - min) * 255) << std::endl;
    }
  }
}