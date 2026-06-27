/* Hands of Straights
You are given an array of integers hand, where hand[i] is the value on the i-th card that Alice owns. Alice wants to split her entire hand into groups such that: every group contains exactly groupSize cards, and the card values in each group form a sequence of groupSize consecutive integers (e.g. [3, 4, 5], [10, 11, 12, 13]).

Examples
Input : hand = [1, 2, 3, 6, 2, 3, 4, 7, 8], groupSize = 3
Output :  True
Explanation :  One possible partition is [1, 2, 3] [2, 3, 4] [6, 7, 8].

Input : hand = [1, 2, 3, 4, 5], groupSize = 4
Output :  false
Explanation :  There is no way to split the hand into groups of 4 consecutive cards.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool handsOfStraights(vector<int> &hand, int groupSize){
    if (hand.size() % groupSize != 0) return false;
    map<int, int> freq;
    for (int card : hand) freq[card]++;
    
    auto it = freq.begin();
    while (it != freq.end()) {
      if (it->second == 0) {
        ++it;
        continue;
      }
      int start = it->first;
      int count = it->second;
      for (int i = 0; i < groupSize; ++i) {
        if (freq[start + i] < count) return false;
        freq[start + i] -= count;
      }
      ++it;
    }
    return true;
  }
};

int main() {
  vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  int groupSize = 3; // Output : True
  Solution sl;
  cout<<(sl.handsOfStraights(hand, groupSize)?"True":"False")<<endl;
  return 0;
}
