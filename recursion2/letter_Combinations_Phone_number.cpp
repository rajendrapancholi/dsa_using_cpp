/* Letter Combinations of a Phone number
Given a string consisting of digits from 2 to 9 (inclusive). Return all possible letter combinations that the number can represent.

Examples
Example 1:
Input:
 digits = "34"
Output:
 [ "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi" ]
Explanation:
The 3 is mapped with "def" and 4 is mapped with "ghi".  
So all possible combinations by replacing the digits with characters are shown in the output.

Example 2:
Input:
 digits = "3"
Output:
 [ "d", "e", "f" ]
Explanation:
The 3 is mapped with "def".
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void letterCombPhone(int i, string digits, string map[], vector<string> &ans, string temp){
    if(i == digits.size()){
      ans.push_back(temp);
      return;
    }
    for(int idx = 0; idx < map[digits[i] - '0'].size(); idx++){
      letterCombPhone(i+ 1, digits, map, ans, temp+map[digits[i] - '0'][idx]);
    }

  }
};

int main() {
  string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  string digits = "5";
  // Output: [ "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi" ]
  Solution sl;
  vector<string> ans;
  sl.letterCombPhone(0, digits, map, ans, "");
  for(auto it: ans) {
    cout<<it<< ", ";
  }
  cout<<endl;

  return 0;
}
