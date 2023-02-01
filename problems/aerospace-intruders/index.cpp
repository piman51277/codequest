#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <regex>

struct Intruder
{
  std::string name;
  int delta;
  int x;
  int y;
};

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  std::regex valueExtractor = std::regex("(.+)_([A-C]):([0-9]+),([0-9]+)");

  for (int i = 0; i < numTestCases; i++)
  {
    int numIntruders = 0;
    std::cin >> numIntruders;

    // toss out the rest of the line
    std::cin.ignore(1);

    std::vector<Intruder> intruders;

    // start processing lines
    for (int j = 0; j < numIntruders; j++)
    {
      // read in the line
      std::string line;
      std::getline(std::cin, line);

      // extract the values
      std::smatch matches;
      std::regex_search(line, matches, valueExtractor);

      Intruder intruder;
      intruder.name = matches[1].str();
      intruder.delta = (matches[2].str()[0] - 'A' + 1) * 10;
      intruder.x = std::stoi(matches[3].str());
      intruder.y = std::stoi(matches[4].str());

      intruders.push_back(intruder);
    }

    // start eliminating intruders
    while (intruders.size() >= 1)
    {
      // find the closest intruder
      int closest = 0;
      int closestDistance = intruders[0].x;
      for (int j = 1; j < intruders.size(); j++)
      {
        int distance = intruders[j].x;
        if (distance < closestDistance || (distance == closestDistance && intruders[j].y > intruders[closest].y))
        {
          closest = j;
          closestDistance = distance;
        }
      }

      // fetch the closest intruder
      Intruder closestIntruder = intruders[closest];

      // output the specs of the closest intruder
      std::cout << "Destroyed Ship: " + closestIntruder.name << " xLoc: " << closestIntruder.x << std::endl;

      // eliminate the closest intruder
      intruders.erase(intruders.begin() + closest);

      // update the remaining intruders
      for (int j = 0; j < intruders.size(); j++)
      {
        intruders[j].x -= intruders[j].delta;
      }
    }
  }
}