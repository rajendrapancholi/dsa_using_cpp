/* Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

Examples
Example 1
Input:
 str = ["flower", "flow", "flight"]
Output:
 "fl"
Explanation:
 All strings in the array begin with the common prefix "fl".

Example 2
Input:
 str = ["apple", "banana", "grape", "mango"]
Output:
 ""
Explanation:
 None of the strings share a common starting sequence, so the result is an empty string.            
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longCommPrefix(vector<string> &str){
    if (str.empty()) return "";
    string ans = "";
    int minSLen = 1e9;
    for(auto s: str) 
      minSLen = min(minSLen, (int)s.size());
    
    for(int i = 0; i < minSLen; i++){
      char tCh = str[0][i];
      bool isMatch = true;
      for(auto s: str)
        if(tCh != s[i]) {
          isMatch = false;
          break;
        }
      
      if(!isMatch) break; 
      ans += tCh;
    }
    return ans;
  }
};

int main() {
  vector<string> str = {"cir","car"}; // Output: "c"
  Solution sl;
  cout<<sl.longCommPrefix(str)<<endl;
  return 0;
}
