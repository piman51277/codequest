#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

struct Node
{
  int minScore;
  int maxScore;
  std::bitset<26> members;
};

// helper split function. God I miss JS
std::vector<std::string> split(std::string str, char delimiter)
{
  std::vector<std::string> internal;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;

  while (getline(ss, tok, delimiter))
  {
    internal.push_back(tok);
  }

  return internal;
}

long long getTeamScore(std::bitset<26> team)
{
  // iterate backwards
  long long score = 0;

  for (int i = 25; i >= 0; i--)
  {
    if (team[i] == 1)
    {
      score += pow(2, 26-i);
    }
  }

  return score;

  return 0;
}

int main()
{
  int numTestCases = 0;
  std::cin >> numTestCases;

  // dump one char
  std::cin.ignore(1);

  for (int i = 0; i < numTestCases; i++)
  {
    // get next line of input
    std::string line;
    std::getline(std::cin, line);

    std::vector<std::string> memberDescriptors = split(line, ' ');


    // create a vector of members
    int memberScores[26];

    // fill with 0s
    std::fill(memberScores, memberScores + 26, 0);

    std::bitset<26> presentMembers;

    for (int j = 0; j < memberDescriptors.size(); j++)
    {
      std::string memberDescriptor = memberDescriptors[j];

      // split the descriptor into its parts delim =
      std::vector<std::string> memberParts = split(memberDescriptor, '=');

      int rawId = memberParts[0][0] - 'A';
      int score = std::stoi(memberParts[1]);

      // create a bitset for the member id
      std::bitset<26> id;
      id.set(rawId);

      // store the score
      memberScores[rawId] = score;

      // add member to present members
      presentMembers |= id;
    }

    // BFS over members (segmented)
    std::queue<Node> candidates;
    std::queue<Node> currentGen;

    // add all single-member teams to the current gen
    for (int j = 0; j < 26; j++)
    {
      if (presentMembers[j] == 0)
      {
        continue;
      }

      int score = memberScores[j];

      Node node;
      node.minScore = score;
      node.maxScore = score;

      std::bitset<26> member;
      member.set(j);

      node.members = member;

      currentGen.push(node);
    }

    candidates = currentGen;

    // The actual BFS
    while (true)
    {
      // the next gen
      std::queue<Node> nextGen;

      // avoid duplicates
      std::set<long> seenTeams;
      // we can't use a set of bitsets because the find function fails with an odd error
      //  compile-time: ‘const std::bitset<26>’ is not derived from ‘const std::__cxx11::sub_match<_BiIter>’

      // iterate over the current gen
      while (currentGen.size() > 0)
      {

        // get the next node
        Node node = currentGen.front();
        currentGen.pop();

        // get all the members that can be added to the team
        std::bitset<26> possibleMembers = presentMembers & ~node.members;

        // iterate over the possible members
        for (int j = 0; j < 26; j++)
        {
          if (possibleMembers[j] == 0)
          {
            continue;
          }

          // get the score of said member
          int score = memberScores[j];

          // would adding this member to the team make it invalid?
          int newMin = std::min(node.minScore, score);
          int newMax = std::max(node.maxScore, score);

          if (newMax - newMin > 10)
          {
            continue;
          }
          // check if we've seen this team before
          std::bitset<26> newMembers = node.members;
          newMembers.set(j);

          // convert the bitset to a long
          long newMembersLong = newMembers.to_ulong();

          // check if we've seen this team before
          if (seenTeams.find(newMembersLong) != seenTeams.end())
          {
            continue;
          }

          // add the team to the seen teams
          seenTeams.insert(newMembersLong);

          // create the new node
          Node newNode;
          newNode.minScore = newMin;
          newNode.maxScore = newMax;
          newNode.members = newMembers;

          // add the new node to the next gen
          nextGen.push(newNode);
        }
      }

      // if the next gen is empty, we're done
      if (nextGen.size() == 0)
      {
        break;
      }

      // othwerwise, set the next gen to the current gen
      currentGen = nextGen;
      candidates = currentGen;
    }


    // extract the candidates
    std::vector<Node> candidateNodes;
    while (candidates.size() > 0)
    {
      candidateNodes.push_back(candidates.front());
      candidates.pop();
    }

    // get candidate with the most senority
    Node bestCandidate = candidateNodes[0];
    long long bestScore = getTeamScore(bestCandidate.members);

    for(int j = 1; j < candidateNodes.size(); j++) {
      Node candidate = candidateNodes[j];
      long long score = getTeamScore(candidate.members);

      if(score > bestScore) {
        bestCandidate = candidate;
        bestScore = score;
      }
    }

    // print the best candidate


    // convert the members back into chars
    std::bitset<26> members = bestCandidate.members;
    std::string memberString = "";
    for (int j = 0; j < 26; j++)
    {
      if (members[j] == 1)
      {
        memberString = memberString + (char)(j + 'A') + " ";
      }
    }

    // remove the trailing space
    memberString = memberString.substr(0, memberString.size() - 1);

    std::cout << memberString << std::endl;
  } 
}