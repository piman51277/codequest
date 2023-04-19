#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int roundUp(int n){
  if(n%2 == 1)
    return n + 1;
  return n + 2;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << roundUp(x) << " " << roundUp(y) << " " << roundUp(z) << std::endl;
  }
}