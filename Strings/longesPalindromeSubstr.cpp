/* Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.
A palindromic substring is a contiguous sequence of characters within the string that reads the same forward and backward.
Example 1
Input: s = "babad"
Output: "bab"
Explanation:
Both "bab" and "aba" are valid palindromic substrings of length 3. Return either.

Example 2
Input: s = "cbbd"
Output: "bb"
Explanation:
The longest palindrome is "bb" of length 2.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
  bool isPalindrome(string s){
    for (int i = 0; i <= s.size() / 2; i++)
      if (s[i] != s[s.size() - i - 1])
        return false;
    return true;
  }

public:
  string longestPalindromeStr(string s){
    string ans = "";
    int maxlen = 0;
    for (int i = 0; i < s.size(); i++){
      for (int j = i; j < s.size(); j++){
        if (isPalindrome(s.substr(i, s.size() - j)) && s.size() - j > maxlen){
          maxlen = s.size() - j;
          ans = s.substr(i, s.size() - j);
        };
      }
    }
    return ans;
  }
};

int main()
{
  string s = "babad";
  Solution sl;
  cout << sl.longestPalindromeStr("cbbd") << endl;
  return 0;
}
