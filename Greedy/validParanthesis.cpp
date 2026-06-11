/* Valid Paranthesis Checker
Find the validity of an input string s that only contains the letters '(', ')' and '*'. A string entered is legitimate if

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
Examples
Input :s = (*))
Output : True
Explanation :The * can be replaced by an opening '(' bracket. The string after replacing the * mark is "(())" and is a valid string.

Input : s = *(()
Output :false
Explanation :The * replaced with any bracket does not form a valid string.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidPar(string &s){
    int min_open = 0, max_open = 0;
    for (const char c : s) {
      if (c == '(') min_open++, max_open++;
      else if (c == ')') min_open--, max_open--;
      else { // c == '*'
        min_open--; // If * acts as ')'
        max_open++; // If * acts as '('
      }
      if (max_open < 0) return false;
      if (min_open < 0) min_open = 0;
    }
    return min_open == 0;
  }
};

int main() {
  string s = "())*"; // Output : True
  Solution sl;
  cout<<(sl.isValidPar(s) ? "True" : "False")<<endl;
  return 0;
}
