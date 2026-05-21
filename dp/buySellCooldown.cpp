/* Buy and Sell Stocks With Cooldown
We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

* We can buy and sell the stock any number of times.
* In order to sell the stock, we need to first buy it on the same or any previous day.
* We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
* We can’t buy a stock on the very next day of selling it. This is the cooldown clause.
Examples

Example 1:
Arr=[4,9, 0, 4, 10]
N=5
Max Profit=11 ((9-4)+(10-4))
Explanation: Buy the stock on 0th day at a price of 4 and sell on the 1st day with a price of 9, then again buy stock at 3rd day at a price of 4 and sell the stock at 4th day at the price of 10

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int helper(vector<int> &prices, int i, int buy, vector<vector<int>> &dp){
    if(i >= prices.size()) return 0;

    if(dp[i][buy] != -1)
      return dp[i][buy];

    int profit = 0;
    
    // Buy
    if(buy == 0)
      profit = max(0 + helper(prices, i + 1, 0, dp), -prices[i] + helper(prices, i + 1, 1, dp));

    // Sell
    if(buy == 1) profit = max(0 + helper(prices, i + 1, 1, dp), prices[i] + helper(prices, i + 2, 0, dp));

    return dp[i][buy] = profit;
  }

public:
  int getMaxProfit(vector<int> &prices){
    int n = prices.size();
    // if(n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    return helper(prices, 0, 0, dp);
  }

  int getMaxProfitTabulation(vector<int> &prices){
    int n = prices.size();
    
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    
    for(int i = n - 1; i >= 0; i--){
      for(int buy = 0; buy < 2; buy++){
        int profit = 0;
        if(buy == 0) profit = max(0 + dp[i + 1][0], -prices[i] + dp[i + 1][1]);

        if(buy == 1) profit = max(0 + dp[i + 1][1], prices[i] + dp[i + 2][0]);
        
        dp[i][buy] = profit;
      }
    }

    return dp[0][0];
  }
};

int main() {
  vector<int> prices = {4,9, 0, 4, 10};
  // vector<int> prices = {1,2,3,0,2};
  Solution sl;
  cout<<sl.getMaxProfit(prices)<<endl;
  cout<<sl.getMaxProfitTabulation(prices)<<endl;
  return 0;
}
