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
    int Cr,Cg,Cb,T,Fr,Fg,Fb,Br,Bg,Bb;

    std::cin >> Cr >> Cg >> Cb >> T >> Fr >> Fg >> Fb >> Br >> Bg >> Bb;

    double distance = std::sqrt(std::pow(Cr - Fr, 2) + std::pow(Cg - Fg, 2) + std::pow(Cb - Fb, 2));

    if(distance <= T){
      std::cout << Br << " " << Bg << " " << Bb << std::endl;
    }else{
      std::cout << Fr << " " << Fg << " " << Fb << std::endl;
    }

  }
}