/* Rod Cutting Problem
Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.

Examples

Input : price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8
Output :25
Explanation :Cut the rod into lengths of 2 and 6 for a total price of 6 + 19= 25.

Input :price = [1, 5, 8, 9], N = 4
Output :10
Explanation :Cut the rod into lengths of 2 and 2 for a total price of 5 + 5 = 10.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
private:
  int solve(int n, int idx, vector<int> &price, vector<vector<int>> &memo){
    if(idx == 0) return n * price[0];

    if(memo[idx][n] != -1) return memo[idx][n];

    int notPick = solve(n, idx - 1, price, memo);
    
    int pick = INT_MIN;
    int rodLength = idx + 1; 
    if(rodLength <= n){
      pick = price[idx] + solve(n - rodLength, idx, price, memo);
    }
    
    return memo[idx][n] = max(notPick, pick);
  }

public:
  int rodCutting(int n, vector<int> &price){
    int len = price.size();
    vector<vector<int>> memo(len, vector<int>(n + 1, -1));
    return solve(n, len-1, price, memo);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,len;

  cin>>n>>len;
  
  vector<int> price(len);
  for(int i = 0; i < len; i++) cin>>price[i];

  Solution sl;
  cout<<"Ans: "<<sl.rodCutting(n, price)<<endl;
  return 0;
}
