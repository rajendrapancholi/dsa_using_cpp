/* Coin Change 2
We are given an array Arr with N distinct coins and a target. We have an infinite supply of each coin denomination. We need to find the number of ways we sum up the coin values to give us the target.

Examples
Example 1:
Input: coins = [2, 4,10], amount = 10
Output: 4
Explanation: The four combinations are:
10 = 10
10 = 4 + 4 + 2
10 = 4 + 2 + 2 + 2
10 = 2 + 2 + 2 + 2 + 2

Example 2:
Input: coins = [5], amount = 5
Output: 1
Explanation: There is one combination: 5 = 5.
            
*/

#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    if (ind == 0) {
        return (T % arr[0] == 0); 
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);

    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);

    return dp[ind][T] = notTaken + taken;
}

long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, -1));
    return countWaysToMakeChangeUtil(arr, n - 1, T, dp);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();

    cout << countWaysToMakeChange(arr, n, target) << endl;
    return 0;
}
