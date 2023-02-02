#include <string>
#include <vector>
#include <bits/stdc++.h>

std::string join(std::vector<std::string> vec, char delimiter)
{
  std::string str = "";
  for (int i = 0; i < vec.size(); i++)
  {
    str += vec[i];
    if (i != vec.size() - 1)
    {
      str += delimiter;
    }
  }
  return str;
}