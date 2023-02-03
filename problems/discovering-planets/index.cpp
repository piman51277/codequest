#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    float temp;
    std::cin >> temp;
    std::string boolWater;
    std::cin >> boolWater;
    std::string boolMagnet;
    std::cin >> boolMagnet;
    float eccentricity;
    std::cin >> eccentricity;

    if(temp > 100){
      std::cout << "The planet is too hot." << std::endl;
    }
    else if(temp < 0){
      std::cout << "The planet is too cold." << std::endl;
    }
    else if(boolWater == "false"){
      std::cout << "The planet has no water." << std::endl;
    }
    else if(boolMagnet == "false"){
      std::cout << "The planet has no magnetic field." << std::endl;
    }
    else if(eccentricity > 0.6){
      std::cout << "The planet's orbit is not ideal." << std::endl;
    }
    else{
      std::cout << "The planet is habitable." << std::endl;
    }
  }
}