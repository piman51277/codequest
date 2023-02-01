#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

void printTransfer(int from, int to){
  //convert 0-2 to A-C
  char fromChar = 'A' + from;
  char toChar = 'A' + to;
  std::cout << fromChar << "->" << toChar << std::endl;
}


void moveStack(int size, int from, int to){
  if(size == 1){
    printTransfer(from, to);
  }
  else{
    int other = 3 - from - to;
    moveStack(size - 1, from, other);
    printTransfer(from, to);
    moveStack(size - 1, other, to);
  }
}


int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int numDisks;
    std::cin >> numDisks;
    std::cout << numDisks << std::endl;

    moveStack(numDisks, 0, 2);
  }
}