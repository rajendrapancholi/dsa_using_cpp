/* Evaluate Boolean Expression to True
Problem Statement: Given an expression, A, with operands and operators (OR, AND, XOR), in how many ways can you evaluate the expression to be true, by grouping it in different ways?.

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.

Pre-requisite: DP-48, DP-49, DP-50, DP-51

Examples
Example 1:
Input: expression = “T|T&F”
Output: 1
Explanation: The only way to get the result as true is:
(T) | (T&F) = T|F = T 

Example 2:
Input: expression = “F|T^F”
Output: 2
Explanation: There are 2 possible ways to get the result as true:
		i. (F|T) ^ F = T ^ F = T
		ii. F | (T^F) = F | T = T
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
int helper(int i, int j, bool isTrue, string &exp) {
  if(i > j) return 0;
  if(i == j) {
    if(isTrue == 1) {
      return exp[i] == 'T' ? 1 : 0;
    } else {
      return exp[i] == 'F' ? 1 : 0;
    }
  }

  int ways = 0;
  
  for(int idx = i + 1; idx <= j - 1; idx += 2){
    int lT = helper(i, idx - 1, 1, exp);
    int lF = helper(i, idx - 1, 0, exp);
    int rT = helper(idx + 1, j, 1, exp);
    int rF = helper(idx + 1, j, 0, exp);
    
    if(exp[idx] == '&')
      (isTrue) ? ways += (lT * rT) : ways += (lF * rT) + (lF * rF) + (lT * rF);
    else if(exp[idx] == '|')
      (isTrue) ? ways += (lF * rT) + (lT * rF) + (lT * rT) : ways += (lF * rF);
    else
      (isTrue) ? ways += (lF * rT) + (lT * rF) : ways += (lF * rF) + (lT * rT);
    }
    return ways;
}

public:
  int noBoolExp(string &exp) {
    int n = exp.size();
    
    return helper(0, n - 1, 1, exp);
  }
};

int main() {
  string exp = "F|T^F";
  Solution sl;
  cout<<sl.noBoolExp(exp)<<endl;
  return 0;
}
