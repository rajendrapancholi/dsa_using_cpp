/* Program name
Power Set: Print all the possible subsequences of the String
Given a string, find all the possible subsequences of the string.
Examples
Input: str = "abc"
Output: [a, ab, abc, ac, b, bc, c]
Explanation: Given string has 7 subsequences.
Input: str = "aa"
Output: [a, a, aa] 
Explanation: Given string has 3 subsequences.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  void helper(int idx, string& str, string tStr, vector<string>& ans){
    int n = str.length();
    if(idx == n){
      ans.push_back(tStr);
      return;
    }
    helper(idx + 1, str, tStr + str[idx], ans);
    helper(idx + 1, str, tStr, ans);
  }
public:
  vector<string> powerSet(string str){
    vector<string> ans;
    helper(0, str, "", ans);
    sort(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  string str = "abc";
  // Output: [a, ab, abc, ac, b, bc, c]
  Solution sl;
  for(auto it: sl.powerSet(str)) {
    cout<<it<<" ";
  }
  cout<<"|"<<endl;
  return 0;
}
