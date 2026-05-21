/* Stock Buy And Sell
Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Examples
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int buyandsell(vector<int> &prices){
    int n = prices.size();
    int profit = 0;
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        if(prices[j] > prices[i]) {
          profit = max(profit, prices[j] - prices[i]);
        }
      }
    }
    return profit;
  }
};

int main() {
  vector<int> prices = {2, 10, 1, 3};

  Solution sl;
  cout<<sl.buyandsell(prices)<<endl;
  return 0;
}
