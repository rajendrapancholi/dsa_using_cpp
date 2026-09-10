/* Stock Buy And Sell
You are given an array of prices where prices[i] is the price of a given stock
on an ith day. You want to maximize your profit by choosing a single day to buy
one stock and choosing a different day in the future to sell that stock. Return
the maximum profit you can achieve from this transaction. If you cannot achieve
any profit, return 0.

Examples
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
6-1 = 5. Note: That buying on day 2 and selling on day 1 is not allowed because
you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int buyAndSell(vector<int> &prices) {
    int n = prices.size();
    int maxProfit = 0;
    // for(int i  = 0; i < n; i++){ // TC O(n^2)
    //   int buy = prices[i];
    //   for(int j = i + 1; j < n; j++){
    //     int sell = prices[j];
    //     if(sell - buy > maxProfit){
    //       maxProfit = sell - buy; 
    //     }
    //   }
    // }
    int minPrice = INT_MAX;
    for(int p: prices){
      if(p < minPrice){
        minPrice = p;
      } else {
        maxProfit = max(maxProfit, p - minPrice);
      }
    }
    return maxProfit;
  }
};

int main() {
  vector<int> prices = {7,6,4,3,1}; // 0
  prices = {7,1,5,3,6,4}; // 5
  Solution sl;
  cout << sl.buyAndSell(prices) << endl;
  return 0;
}