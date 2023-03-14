#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

struct Node
{
  int val;
  std::string path;
};

std::vector<Node> getLineOfInts(int n)
{
  std::vector<Node> nodes;
  for (int i = 0; i < n; i++)
  {
    int val;
    std::cin >> val;
    Node node;
    node.val = val;
    node.path = "";
    nodes.push_back(node);
  }
  return nodes;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int k;
    std::cin >> k;
    std::vector<std::vector<Node>> nodes;

    for (int i = 0; i < k + 1; i++)
    {
      nodes.push_back(getLineOfInts(i + 1));
    }

    // DP
    for (int i = k - 1; i >= 0; i--)
    {
      for (int j = 0; j < nodes[i].size(); j++)
      {
        int left = nodes[i + 1][j].val;
        int right = nodes[i + 1][j + 1].val;
        if (left > right)
        {
          nodes[i][j].val += left;
          nodes[i][j].path = "L" + nodes[i + 1][j].path;
        }
        else
        {
          nodes[i][j].val += right;
          nodes[i][j].path += "R" + nodes[i + 1][j + 1].path;
        }
      }
    }

    // find the path and max value
    int max = nodes[0][0].val;
    std::string path = nodes[0][0].path;

    std::cout << path << " = " << max << std::endl;
  }
}