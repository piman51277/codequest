#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

int main(){
  int numTestCases = 0;
  std::cin >> numTestCases;

  //get rid of newline
  std::cin.ignore(1);


  //handle test cases
  for (int i = 0; i < numTestCases; i++){
    std::string caseString;

    std::getline(std::cin, caseString);

    //iterate over the string
    int vowels = 0;
    for (char ch : caseString)
    {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      {
        vowels++;
      } 
    }
    std::cout << vowels << std::endl;
  }
}