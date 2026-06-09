/* Roman Numerals to Integer
Roman numerals are represented by seven different symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
For example: 2 is written as II, 12 is written as XII, 27 is written as XXVII.
Roman numerals are usually written largest to smallest from left to right. But in six special cases, subtraction is used instead of addition:
I before V or X → 4 and 9,
X before L or C → 40 and 90,
C before D or M → 400 and 900
Given a Roman numeral, convert it to an integer.

Examples
Example 1:
Input:
 s = "LVIII"
Output:
 58
Explanation:
 L = 50, V= 5, III = 3.

Example 2:
Input:
 s = "MCMXCIV"
Output:
 1994
Explanation:
 M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int romanToInt(string &s) { 
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    if(s.size() == 1) return roman[s[0]];
    
    int ans = 0;
   
    for(int i = 0; i < s.size(); i++){
      if(i + 1 >= s.size()){
        ans += roman[s[i]];
      } else if(roman[s[i]] >= roman[s[i + 1]]){
        ans += roman[s[i]];
      } else if(roman[s[i]] < roman[s[i + 1]]){
        ans += roman[s[i + 1]] - roman[s[i]];
        i++;
      }
    }
    return ans;
  }
};

int main() {
  string s = "MCMXCIV"; // Output: 58
  Solution sl;
  cout<<sl.romanToInt(s)<<endl;
  return 0;
}
