#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

/**
 * Color will be represented by a value from 0-7
 * (in binary) the base colors are
 * 100 Red
 * 010 Green
 * 001 Blue
 */
struct lightPulse
{
  int index;
  int direction;
  int color;
};

std::vector<char> colors = {'X','B','G','C','R','M','Y','W'};

void printStrip(int tapeSize, std::vector<lightPulse> lightObjects)
{

  // resolve the final colors of the strip
  std::vector<int> strip;
  for (int k = 0; k < tapeSize; k++)
  {
    strip.push_back(0);
  }

  // put LEDs onto the tape
  for (lightPulse pulse : lightObjects)
  {
    int index = pulse.index;
    int color = pulse.color;
    strip[index] = (strip[index]) | (pulse.color);
  }

  // print out the values
  for (int led : strip)
  {
    std::cout << colors[led];
  }

  std::cout << std::endl;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    // read in the 3-tuple with the settings
    int tapeSize, lights, itrseconds;
    std::cin >> tapeSize >> lights >> itrseconds;
    std::vector<lightPulse> lightObjects;

    for (int k = 0; k < lights; k++)
    {
      char color;
      int index, direction;
      std::cin >> color >> index >> direction;

      int colorNum = 0;
      if (color == 'R')
        colorNum = 4;
      if (color == 'G')
        colorNum = 2;
      if (color == 'B')
        colorNum = 1;

      lightPulse tmp = {index, direction, colorNum};
      lightObjects.push_back(tmp);
    }

    printStrip(tapeSize, lightObjects);

    // actually simulate the lights
    for (int second = 0; second < itrseconds; second++)
    {
      for (int k = 0; k < lightObjects.size(); k++)
      {
        lightPulse pulse = lightObjects[k];

        int index = pulse.index;

        // overloads for rebounds
        if (lightObjects[k].direction == -1 && index == 0)
        {
          lightObjects[k].direction = 1;
        }
        else if (lightObjects[k].direction == 1 && index == tapeSize - 1)
        {
          lightObjects[k].direction = -1;
        }

        lightObjects[k].index += lightObjects[k].direction;
      }

      printStrip(tapeSize, lightObjects);
    }
  }
}