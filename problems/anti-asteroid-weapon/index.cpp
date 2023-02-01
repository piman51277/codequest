#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

struct Asteroid
{
  int x;
  int y;
  double distance;
};

bool compareAsteroids(Asteroid a, Asteroid b)
{
  return a.distance < b.distance;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int count = 0;
    std::cin >> count;
    std::vector<Asteroid> asteroids;

    for (int i = 0; i < count; i++)
    {
      int x, y;
      std::cin >> x >> y;

      double distance = sqrt(x * x + y * y);
      Asteroid asteroid = {x, y, distance};
      asteroids.push_back(asteroid);
    }

    std::sort(asteroids.begin(), asteroids.end(), compareAsteroids);

    for (int i = 0; i < count; i++)
    {
      std::cout << asteroids[i].x << " " << asteroids[i].y << std::endl;
    }
  }
};