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
    int n, k;
    std::cin >> n >> k;

    // create a vector with numbered people
    std::vector<int> people;
    for (int j = 1; j <= n; j++)
    {
      people.push_back(j);
    }

    while (people.size() > 1)
    {
      // remove the kth person
      int target = (k - 1) % people.size();
      people.erase(people.begin() + target);
      // reorder the vector so the very next person is at the front
      std::rotate(people.begin(), people.begin() + target, people.end());
    }

    //last person
    int delta = people[0] - 1;
    int startingPoint = (1-delta )% n;
    if (startingPoint <= 0)
    {
      startingPoint += n;
    }
    std::cout << startingPoint << std::endl;


  }
}