#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

typedef std::vector<std::vector<bool>> Grid;

Grid stepBoard(Grid initial)
{

  // get the dimensions of the grid
  int rows = initial.size();
  int cols = initial[0].size();

  // create a board to write on
  Grid next(rows, std::vector<bool>(cols, false));

  // iterate over the board
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < cols; y++)
    {
      int liveNeighbors = 0;

      // check the neighbors
      if (x > 0 && y > 0 && initial[x - 1][y - 1])
        liveNeighbors++;
      if (x > 0 && initial[x - 1][y])
        liveNeighbors++;
      if (x > 0 && y < cols - 1 && initial[x - 1][y + 1])
        liveNeighbors++;
      if (y > 0 && initial[x][y - 1])
        liveNeighbors++;
      if (y < cols - 1 && initial[x][y + 1])
        liveNeighbors++;
      if (x < rows - 1 && y > 0 && initial[x + 1][y - 1])
        liveNeighbors++;
      if (x < rows - 1 && initial[x + 1][y])
        liveNeighbors++;
      if (x < rows - 1 && y < cols - 1 && initial[x + 1][y + 1])
        liveNeighbors++;

      // undercrowding
      if (liveNeighbors <= 1)
      {
        next[x][y] = false;
      }

      // overcrowding
      else if (liveNeighbors >= 4)
      {
        next[x][y] = false;
      }

      // stasis
      else if (liveNeighbors == 2)
      {
        next[x][y] = initial[x][y];
      }

      // reproduction
      else if (liveNeighbors == 3)
      {
        next[x][y] = true;
      }
    }
  }

  // return the board
  return next;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    //read in the number of gens
    int gens;
    std::cin >> gens;

    //toss a newline
    std::cin.ignore(1);

    //create an empty 10x10
    Grid board(10, std::vector<bool>(10, false));

    //read in the board
    for (int x = 0; x < 10; x++)
    {
      std::string line;
      std::getline(std::cin, line);

      for (int y = 0; y < 10; y++)
      {
        if (line[y] == '1')
        {
          board[x][y] = true;
        }
      }
    }

    //run the board
    for (int j = 0; j < gens; j++)
    {
      board = stepBoard(board);
    }

    //print the board
    for (int x = 0; x < 10;x++){
      for(int y = 0; y < 10; y++){
        if(board[x][y]){
          std::cout << "1";
        }else{
          std::cout << "0";
        }
      }
      std::cout << std::endl;
    }
  }
}