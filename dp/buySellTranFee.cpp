/* Buy and Sell Stocks With Transaction Fees
We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any previous day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
After every transaction, there is a transaction fee (‘fee’) associated with it.

Examples
Example 1:
Array=[1, 3, 2, 8, 4, 9]
N=6
Fee=2
Max Profit=8 (5(8-1-2)+3(9-4-2))
Explanation: Buy the stock on 0th day at a price of 1 and sell on the 3rd day at a price 8 incurring a fee of 2, then again buy stock at 4th day at a price 4 and sell the stock at 5th day at price of 9 incurring a fee of 2.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int helper(vector<int> &prices, int fee, int i, int buy, vector<vector<int>> &dp){
    if(i == prices.size()) return 0;

    int profit = 0;

    if(dp[i][buy] != -1) return dp[i][buy];

    // buy
    // 1. skip on today, 2. buy on second day
    if(buy == 0) profit = max(0 + helper(prices, fee, i + 1, 0, dp), -prices[i] -fee + helper(prices, fee, i + 1, 1, dp));

    // sell 
    // 1. skip on today, 2. sell on second day
    if(buy == 1) profit = max(0 + helper(prices, fee, i + 1, 1, dp), prices[i] + helper(prices, fee, i + 1, 0, dp));

    return dp[i][buy] = profit;
  }

public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return helper(prices, fee, 0, 0, dp);
  }

  int maxProfitTab(vector<int> &prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for(int i = n - 1; i >= 0; i--){
      for(int buy = 0; buy < 2; buy++){
        int profit = 0;
        
        // buy
        if(buy == 0) profit = max(0 + dp[i + 1][0], -prices[i]-fee + dp[i + 1][1]);
        
        // sell
        if(buy == 1) profit = max(0 + dp[i + 1][1], prices[i] + dp[i + 1][0]);

        dp[i][buy] = profit;
      }
    }

    return dp[0][0];
  }
};

int main() {
  vector<int> prices = {1, 3, 2, 8, 4, 9};
  int fee = 2;
  Solution sl;
  cout<<sl.maxProfit(prices, fee)<<endl;
  cout<<sl.maxProfitTab(prices, fee)<<endl;
  return 0;
}
