#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

struct launchFrame{
  std::string date;
  std::string time;
  int thickness;
  float windspeed;
  int direction;
};

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int timeCount = 0;
    std::cin >> timeCount;

    std::vector <launchFrame> launchFrames;

    for (int j = 0; j < timeCount; j++)
    {
      launchFrame frame;
      std::cin >> frame.date >> frame.time >> frame.thickness >> frame.windspeed >> frame.direction;
      launchFrames.push_back(frame);
    }

    bool foundFrame = false;
    for(launchFrame k : launchFrames){
      if(k.thickness > 1000){
        continue;
      }

      float radians = k.direction * M_PI / 180;

      float x = k.windspeed * cos(radians);
      float y = k.windspeed * sin(radians);

      if(std::abs(x) > 20.0 || std::abs(y) > 40.0){
        continue;
      }

      std::cout << k.date << " " << k.time << std::endl;
      foundFrame = true;
      break;
    }

    if(!foundFrame){
      std::cout << "ABORT LAUNCH" << std::endl;
    }
  }
}