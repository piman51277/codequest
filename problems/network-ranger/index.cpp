#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <bitset>

std::bitset<32> convertToBinary(std::string ip)
{
  // split into 4 octets
  std::vector<std::string> octets;

  std::string octet = "";
  for (int i = 0; i < ip.length(); i++)
  {
    if (ip[i] == '.')
    {
      octets.push_back(octet);
      octet = "";
    }
    else
    {
      octet += ip[i];
    }
  }

  octets.push_back(octet);

  // convert octets to unsigned ints
  std::vector<unsigned int> octetInts;
  for (int i = 0; i < octets.size(); i++)
  {
    octetInts.push_back(std::stoi(octets[i]));
  }

  // convert to binary
  std::bitset<32> binary;
  for (int i = 0; i < 4; i++)
  {
    std::bitset<8> octetBinary(octetInts[3 - i]);
    for (int j = 0; j < 8; j++)
    {
      binary[i * 8 + j] = octetBinary[j];
    }
  }

  return binary;
}

std::string binaryToIP(std::bitset<32> binary)
{
  std::string ip = "";
  for (int i = 3; i >= 0; i--)
  {
    std::bitset<8> octetBinary;
    for (int j = 0; j < 8; j++)
    {
      octetBinary[j] = binary[i * 8 + j];
    }

    ip += std::to_string(octetBinary.to_ulong());
    if (i != 0)
    {
      ip += ".";
    }
  }

  return ip;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)
  {
    int ips = 0;
    std::cin >> ips;

    // read in ips
    std::vector<std::string> ipStrings;
    for (int j = 0; j < ips; j++)
    {
      std::string ip;
      std::cin >> ip;
      ipStrings.push_back(ip);
    }

    // convert to binary
    std::vector<std::bitset<32>> ipBinaries;
    for (int j = 0; j < ips; j++)
    {
      ipBinaries.push_back(convertToBinary(ipStrings[j]));
    }

    // find the longest common header
    int longestCommonHeader = 0;
    std::bitset<32> commonHeader;
    for (int j = 31; j >= 0; j--)
    {
      bool same = true;
      for (int k = 1; k < ips; k++)
      {
        if (ipBinaries[k][j] != ipBinaries[0][j])
        {
          same = false;
          break;
        }
      }

      if (same)
      {
        longestCommonHeader++;
        commonHeader[j] = ipBinaries[0][j];
      }
      else
      {
        break;
      }
    }

    // print out the result
    std::cout << binaryToIP(commonHeader) << "/" << longestCommonHeader << std::endl;
  }
}