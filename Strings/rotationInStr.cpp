/* Check if one string is rotation of another
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position. For example, if s = "abcde", then it will be "bcdea" after one shift.
Examples
Example 1:
Input:
 s = "rotation", goal = "tionrota"
Output:
 true
Explanation:
 After multiple left shifts on "rotation", we get:
    1st shift → "otationr"
    2nd shift → "tationro"
    3rd shift → "ationrot"
    4th shift → "tionrota"
    So the goal string can be obtained by rotating the original string.

Example 2:
Input:
 s = "hello", goal = "lohelx"
Output:
 false
Explanation:
 
Even after all possible rotations of "hello", we cannot form "lohelx" due to the presence of an extra character 'x'. Hence, it's not possible.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isRotation(string s, string g){
    int sl = s.size(), gl = g.size();
    if(sl != gl) return false;
    for(int i = 0; i < sl; i++){
      string rotatedStr = s.substr(i) + s.substr(0, i); // ith to end + 0th to ith 
      cout<<"rota: "<<rotatedStr<<endl;
      if(rotatedStr == g) return true;
    }
    return false;
  }
};

int main() {
  string s = "rotation", g = "tionrota"; // Output: true
  Solution sl;
  cout<<sl.isRotation(s, g)<<endl;
  return 0;
}
