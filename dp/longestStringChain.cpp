/* Longest String Chain
Problem Statement: Given an array of strings words[], the task is to return the longest string chain. A string chain is defined as a sequence of words where:

Each word (except the first) can be formed by inserting exactly one character into the previous word.
The first word of the chain can be any word from the words[] array.
The task is to determine the length of the longest chain.

Examples
Example 1:
Input:
 words = ["a", "ab", "abc", "abcd", "abcde"]  
Output:
 5  
Explanation:
 
The longest chain is ["a", "ab", "abc", "abcd", "abcde"].  
Each word in the chain is formed by adding exactly one character to the previous word.

Example 2:
Input:
 words = ["dog", "dogs", "dots", "dot", "d", "do"]  
Output:
 4  
Explanation:
  
The longest chain is ["d", "do", "dot", "dots"].  
Each word is formed by inserting one character into the previous word.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  static bool compare(string &s, string &t){
    return s.size() < t.size();
  }
  
  bool checkPossible(string &s, string &t){
    if(s.size() != t.size() + 1) return false;
    int i = 0, j = 0;
    while (i < s.size()){
      if(j < t.size() && s[i] == t[j]) {
        i++, j++;
      } else{
        i++;
      }
    }
    if(i == s.size() && j == t.size()) return true;
    return false;    
  }
  
public:
  int longestStrChain(vector<string> &words){
    int n = words.size();
    sort(words.begin(), words.end(), compare);
    vector<int> dp(n, 1);
    int maxLen = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < i; j++){
        if(checkPossible(words[i], words[j]) && dp[i] < dp[j] + 1){
          dp[i] = dp[j] + 1;
        }
      }
      if(dp[i] > maxLen) maxLen = dp[i];
    }
    for(auto el: dp){
      cout<<el<< ' ';
    }
    cout<<endl;
    return maxLen;
  }
};

int main() {
  vector<string> words = {"dog", "dogs", "dots", "dot", "d", "do"};
  Solution sl;

  cout<<sl.longestStrChain(words)<<endl;
  return 0;
}
