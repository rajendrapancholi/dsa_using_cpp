/* Distinct Subsequences
Problem Statement : Given two strings s and t, return the number of distinct subsequences of s that equal t.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters. For example, "ace" is a subsequence of "abcde" while "aec" is not.
The task is to count how many different ways we can form t from s by deleting some (or no) characters from s.
Examples
Input: s = "axbxax", t = "axa"
Output: 2
Explanation: In the string "axbxax", there are two distinct subsequences "axa":
(a)(x)bx(a)x
(a)xb(x)(a)x 
Input: s = "babgbag", t = "bag"
Output: 5
Explanation: In the string "babgbag", there are five distinct subsequences "bag":
(ba)(b)(ga)(g)
(ba)(bg)(ag)
(bab)(ga)(g)
(bab)(g)(ag)
(babg)(a)(g) 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int helper(int i, int j, string &s, string &t){
    if(j == t.size()) return 1;
    if(i == s.size()) return 0;
    
    if(s[i] == t[j]){
      int pick = helper(i+1, j+1, s, t);
      int notPick = helper(i+1, j, s, t);
      return pick + notPick;
    } else {
      return helper(i+1, j, s, t);

    }
  }
public:
  int shortestCommSub(string &s, string &t){
    return helper(0, 0, s, t);
  }
};

int main() {
  string s = "babgbag", t = "bag";

  Solution sl;
  cout<<sl.shortestCommSub(s, t);
  return 0;
}
