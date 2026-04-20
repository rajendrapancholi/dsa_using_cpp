/* Minimum Coins
Given an integer array of coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that are needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. There are infinite numbers of coins of each type

Examples
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1. We need 3 coins to make up the amount 11.
Input : coins = [2, 5], amount = 3
Output: -1
Explanation :  It's not possible to make amount 3 with coins 2 and 5. Since we can't combine the coin 2 and 5 to make the amount 3, the output is -1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  int solve(vector<int> &arr, int amount, vector<int> &memo){
    if(amount == 0) return 0;
    if(amount < 0) return 1e9;

    if(memo[amount] != 1e9) return memo[amount];

    int count = 1e9;
    for(auto el: arr){
     int res = solve(arr, amount-el, memo);
     if(res != 1e9){
      count = min(count, 1 + res);
     }
    }
    return memo[amount] = count;
  }

public:
  int minimumCoins(vector<int> &arr, int amount, int len){
    vector<int> memo(amount+1, 1e9);
    return solve(arr, amount, memo);
  }

  int minimumCoins2(vector<int> &arr, int amount, int len){
    vector<int> memo(amount+1, 1e9);
    memo[0] = 0;
    for(int i = 1; i <= amount; i++){
      for(auto el: arr){
        if(memo[i-el] != 1e9){
          memo[i] = min(memo[i], 1 + memo[i-el]);
        }
      }
    }
    return memo[amount] != 1e9 ? memo[amount] : -1;
  }
};

int main() {
  int amount = 0, len = 0;
  cin>>amount;
  cin>>len;
  vector<int> arr(len);

  for(int i=0; i<len; i++) cin>>arr[i];

  Solution sl;

  cout<<sl.minimumCoins(arr, amount, len)<<endl;
  cout<<sl.minimumCoins2(arr, amount, len)<<endl;
  return 0;
}
