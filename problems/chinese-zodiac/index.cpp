#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

std::vector<std::string> elements = {"Wood", "Fire", "Earth", "Metal", "Water"};
std::vector<std::string> animals = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int year = 0;
    std::cin >> year;

    std::cout << year << " ";

    if (year % 2 == 0)
    {
      std::cout << "Yang ";
    }
    else
    {
      std::cout << "Yin ";
    }

    // elements
    int element = std::floor(((year - 4) % 10) / 2);
    std::cout << elements[element] << " ";

    int animal = (year - 4) % 12;
    std::cout << animals[animal] << std::endl;
  }
}