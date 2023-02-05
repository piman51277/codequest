#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <utility>

struct Node
{
  int id;
  int neighbors[4];
  bool isEndpoint;
};

int getIDFromPosition(int x, int y, int width)
{
  return y * width + x;
}

bool isCharacterEntrance(char c)
{
  return c == '^' || c == '<' || c == '>' || c == 'v';
}

bool isCharacterWall(char c)
{
  return c == '|' || c == '-' || isCharacterEntrance(c);
}

std::vector<Node> parseMaze(std::vector<std::string> maze, int width, int height)
{

  // first, initialize the nodes
  std::vector<Node> nodes(width * height);
  for (int i = 0; i < width * height; i++)
  {
    Node node;
    node.id = i;
    node.neighbors[0] = 0;
    node.neighbors[1] = 0;
    node.neighbors[2] = 0;
    node.neighbors[3] = 0;
    node.isEndpoint = false;
    nodes[i] = node;
  }

  // iterate through all positions in the maze and figure out which nodes are connected
  for (int x = 0; x < width; x++)
  {
    for (int y = 0; y < height; y++)
    {
      // get the id of the current node
      int id = getIDFromPosition(x, y, width);

      // fetch the current node
      Node &node = nodes[id];

      // get characters representing the walls of said node
      // the nodes are represented as a 4x3 grid of characters
      char top = maze[y * 2][x * 3 + 1];
      char right = maze[y * 2 + 1][x * 3 + 3];
      char bottom = maze[y * 2 + 2][x * 3 + 1];
      char left = maze[y * 2 + 1][x * 3];

      // the neighbor array is ordered as follows:
      //  top, right, bottom, left

      if (x > 0 && !isCharacterWall(left))
      {
        node.neighbors[3] = getIDFromPosition(x - 1, y, width);
      }
      if (x < width - 1 && !isCharacterWall(right))
      {
        node.neighbors[1] = getIDFromPosition(x + 1, y, width);
      }
      if (y > 0 && !isCharacterWall(top))
      {
        node.neighbors[0] = getIDFromPosition(x, y - 1, width);
      }
      if (y < height - 1 && !isCharacterWall(bottom))
      {
        node.neighbors[2] = getIDFromPosition(x, y + 1, width);
      }

      // if any of the walls are entrances, this node is an endpoint
      if (isCharacterEntrance(top) || isCharacterEntrance(right) || isCharacterEntrance(bottom) || isCharacterEntrance(left))
      {
        node.isEndpoint = true;
      }
    }
  }

  return nodes;
}

// tbh, the hardest part of this problem is parsing the input
int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    // get the number of lines and width of said lines
    int lines, lineWidth;
    std::cin >> lines >> lineWidth;

    // toss the newline
    std::cin.ignore(1);

    std::vector<std::string> maze;
    for (int j = 0; j < lines; j++)
    {
      std::string line;
      std::getline(std::cin, line);
      maze.push_back(line);
    }

    // find the width/height in cells
    int width = (lineWidth - 1) / 3;
    int height = (lines - 1) / 2;

    std::vector<Node> nodes = parseMaze(maze, width, height);

    // parse the maze
    Node start;

    // find the start node
    for (Node node : nodes)
    {
      if (node.isEndpoint)
      {
        start = node;
        break;
      }
    }

    // use BFS to find the shortest path
    std::queue<std::pair<Node, int>> queue;
    std::set<int> visited;

    // add the start node to the queue
    queue.push({start, 1});

    while (!queue.empty())
    {
      std::pair<Node, int> pair = queue.front();
      Node node = pair.first;
      int distance = pair.second;
      queue.pop();

      // if the node has already been visited, skip it
      if (visited.find(node.id) != visited.end())
      {
        continue;
      }

      // mark the node as visited
      visited.insert(node.id);

      // if the node is an endpoint, we're done
      if (node.isEndpoint && node.id != start.id)
      {
        std::cout << distance << std::endl;
        break;
      }

      // add all neighbors to the queue
      for (int i = 0; i < 4; i++)
      {
        if (node.neighbors[i] != 0)
        {
          Node neighbor = nodes[node.neighbors[i]];
          queue.push({neighbor, distance + 1});
        }
      }
    }
  }
}