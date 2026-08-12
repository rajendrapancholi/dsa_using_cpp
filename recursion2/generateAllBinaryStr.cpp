/* Generate all binary strings
Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.
A binary string is a string consisting only of characters '0' and '1'.
Examples
Example 1:
Input:
 n = 3  
Output:
 ["000", "001", "010", "100", "101"]  
Explanation:
 All binary strings of length 3 that do not contain consecutive 1s.

Example 2:
Input:
 n = 2  
Output:
 ["00", "01", "10"]  
Explanation:
 All binary strings of length 2 that do not contain consecutive 1s.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void genBinStr(int n, vector<string> &ans, string crr){
    if(crr.length() == n){
      ans.push_back(crr);
      return;
    }
    genBinStr(n, ans, crr + "0");
    if(crr.empty() || crr.back() != '1'){
      genBinStr(n, ans, crr + '1');
      return;
    }
  }
};

int main() {
  int n = 3; // ["000", "001", "010", "100", "101"]
  vector<string> ans;
  Solution sl;
  sl.genBinStr(n, ans, "");
  for(auto it: ans) {
    cout<<it<<endl;
  }
  return 0;
}
