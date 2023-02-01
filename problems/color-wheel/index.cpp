#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>


int main()
{

  // lookup table - This kindof sucks, but it's the easiest and fastest way to do it
  std::vector<std::string> colorNames = {"red-violet", "violet", "blue-violet", "blue-green", "green", "yellow-green", "yellow-orange", "orange", "red-orange"};

  // the two colors needed are in this order of bits Blue, Red, Yellow
  int colorParents[9] = {6, 6, 6, 5, 5, 5, 3, 3, 3};



  int numTestCases = 0;
  std::cin >> numTestCases;

  // toss the newline
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
      //get the color name
      std::string color;
      std::getline(std::cin, color);

      //get the color id
      int colorId = std::find(colorNames.begin(), colorNames.end(), color) - colorNames.begin();

      //if npos
      if(colorId == 9){
        std::cout << "No colors need to be mixed to make " << color << "." << std::endl;
        continue;
      }

      std::cout << "In order to make " << color << ", ";

      if (colorId <= 2)
      {
        //blue-red
        std::cout << "blue and red ";
      }
      else if(colorId <= 5){
        //blue=yellow
        std::cout << "blue and yellow ";
      }
      else if(colorId <= 8){
        //red-yellow
        std::cout << "red and yellow ";
      }

      std::cout << "must be mixed." << std::endl;
      
  }
}