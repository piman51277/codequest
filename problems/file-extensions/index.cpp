#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  //dump the newline
  std::cin.ignore(1);

  std::map<std::string, int> extensionCount;

  //vector of extension found order
  std::vector<std::string> extensionOrder;

  for (int i = 0; i < numTestCases; i++)
  {
    //read in the line
    std::string line;
    std::getline(std::cin, line);

    //find the last period
    int lastPeriod = line.find_last_of('.');

    //get the extension
    std::string extension = line.substr(lastPeriod + 1);

    //check if it's in the map
    if (extensionCount.find(extension) == extensionCount.end())
    {
      //not in the map, add it
      extensionCount[extension] = 1;
      extensionOrder.push_back(extension);
    }
    else
    {
      //already in the map, increment it
      extensionCount[extension]++;
    }
  }

  //read out extension counts
  for (std::string element : extensionOrder)
  {
    std::cout << element << " " << extensionCount[element] << std::endl;
  }
}