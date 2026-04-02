/* Subset sum equals to target
Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.

Example 1
Input: arr = [1, 2, 7, 3], target = 6
Output: True
Explanation: There is a subset (1, 2, 3) with sum 6.
Example 2
Input: arr = [2, 3, 5], target = 6
Output: False
Explanation: There is no subset with sum 6.
*/


#include <bits/stdc++.h>
using namespace std;


class Solution{   
private: 
    bool helper(vector<int>& arr, int target, int idx, vector<vector<int>>& dp){
        // base cases
        if(target == 0) return true;
        if(idx == 0) return arr[idx] == target;

        if (dp[idx][target] != -1) return dp[idx][target];

        // Not pick curr element
        bool notPick = helper(arr, target, idx-1, dp);

        bool pick = false;
        if(arr[idx]<=target){
            pick = helper(arr, target - arr[idx], idx - 1, dp);
        }

        return  dp[idx][target] = notPick || pick;
    }

public:
    bool isSubsetSum(vector<int>arr, int target){
        int idx = arr.size();
        vector<vector<int>> dp(idx, vector<int>(target + 1, -1));
        bool result = helper(arr, target, idx-1, dp);
        return result;
    }
};





