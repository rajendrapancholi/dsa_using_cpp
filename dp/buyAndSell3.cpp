#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(vector<int>& prices, int i, int buy, int capacity, vector<vector<vector<int>>> &dp){
        if(i == prices.size() || capacity == 0) return 0;

        // If the result is already calculated, return it.
        if (dp[i][buy][capacity] != -1)
            return dp[i][buy][capacity];

        int profit = 0;
        
        // buy
        // Option 1: Skip buying today.
        // Option 2: Buy the stock today.
        if(buy == 0) profit = max(0 + helper(prices, i + 1, 0, capacity, dp), -prices[i] + helper(prices, i + 1, 1, capacity, dp));
        
        // sell
        // Option 1: Skip selling today.
        // Option 2: Sell the stock today.
        if(buy == 1) profit = max(0 + helper(prices, i + 1, 1, capacity, dp), prices[i] + helper(prices, i + 1, 0, capacity - 1, dp));
        return dp[i][buy][capacity] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, 0, 0, 2, dp);
    }
};

int main(){
  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  Solution sl;
  cout<<sl.maxProfit(prices)<<endl;
  return 0;
}