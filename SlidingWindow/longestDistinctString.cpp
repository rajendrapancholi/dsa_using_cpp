/* Longest Substring with At Most K Distinct Characters
Problem Statement: Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters

Examples

Input :s = "aababbcaacc" , k = 2
Output :6
Explanation :The longest substring with at most two distinct characters is "aababb".
The length of the string 6

Input : s = "abcddefg" , k = 3
Output : 4
Explanation : The longest substring with at most three distinct characters is "bcdd".
The length of the string 4.
*/

#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
  int longestDistSubstrAtMost(string &s, int k){
   int maxlen = 0, n = s.size();
   for(int i = 0; i < n; i++) {
    unordered_map<char, int> mp;
    for(int j = i; j < n; j++){
      mp[s[j]]++;
      if(mp.size() <= k){
        maxlen = max(maxlen, j - i + 1);
      } else if(mp.size() > k) break;
    }
   }
   return maxlen;
  }

  int longestDistSubstrAtMostSW(string &s, int k){
    int maxlen = 0, n = s.size(), left = 0;
    unordered_map<char, int> mp;
    for(int right = 0; right < n; right++) {
      mp[s[right]]++;
      while(mp.size() > k) {
        mp[s[left]]--;
        if(mp[s[left]] == 0) {
          mp.erase(s[left]);
        }
        left++;
      }
      maxlen = max(maxlen, right - left + 1);
    }
    return maxlen;
  }

  
};

int main() {
  // string s = "aababbcaacc"; int k = 2; // Output :6
  string s = "abcddefg"; int k = 3;
  Solution sl;
  cout<<sl.longestDistSubstrAtMost(s, k)<<endl;
  cout<<sl.longestDistSubstrAtMostSW(s, k)<<endl;
  return 0;
}
