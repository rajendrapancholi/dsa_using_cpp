/* Sum of all Subsets
Given an array print all the sum of the subset generated from it, in the increasing order.

Examples

Input: N = 3, arr[] = {5,2,1}
Output: 0,1,2,3,5,6,7,8
Explanation: We have to find all the subset's sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

Input: N=3,arr[]= {3,1,2}
Output: 0,1,2,3,3,4,5,6
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6

Bitmasking Approach
Algorithm
The brute force method treats each subset as a binary representation of choices: for every element in the array, you either include it in the subset or exclude it. This is represented by a bitmask from 0 to 2^N - 1. For each mask, we check each bit position—if the bit is set, include the corresponding element in the sum; otherwise, skip it. This way, we can calculate the sum for all possible subsets. The results are then sorted before printing to ensure increasing order.
Initialize an empty list to store subset sums
Iterate mask from 0 to (2^N - 1)
For each mask, initialize sum = 0
Check each bit of the mask from 0 to N-1
If a bit is set, add the corresponding array element to sum
Store the sum in the list
After processing all masks, sort the list
Output the sorted list of sums
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> subsetSumM1(vector<int>& arr){ // tc = O(2^n * n)
    int n = arr.size();
    vector<int> sums;
    for(int msk = 0; msk < (1 << n); msk++){
      int sum = 0;
      for(int i = 0; i < n; i++){
        if(msk & (1 << i))
          sum += arr[i];
      }
      sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());
    return sums;
  }

  void subsetSumM2(int i, int currSum, vector<int>& arr, vector<int>& sums){ // tc O(2^n)
    if(i == arr.size()){
      sums.push_back(currSum);
      return;
    } 
    subsetSumM2(i + 1, currSum + arr[i], arr, sums);
    subsetSumM2(i + 1, currSum, arr, sums);
  }
};

int main() {
  vector<int> arr = {5,2,1};
  // Output: 0,1,2,3,5,6,7,8
  Solution sl;
  for(auto it: sl.subsetSumM1(arr)) {
    cout<<it<<" ";
  }

  cout<<endl;
  cout<<endl;
  
  vector<int> sums;
  sl.subsetSumM2(0, 0, arr, sums);

  sort(sums.begin(), sums.end());
  
  for(auto it: sums) {
    cout<<it<<" ";
  }

  return 0;
}
