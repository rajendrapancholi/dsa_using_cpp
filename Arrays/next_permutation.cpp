/* next_permutation : find next lexicographically greater permutation
Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

Examples
Input: Arr[] = {1,3,2}
Output: {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
Input : Arr[] = {3,2,1}
Output: {1,2,3}
Explanation : As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the lowest permutation. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextPermutation(vector<int>& arr) {
    int n = arr.size();
    // vector<vector<int>> allPermutations;
    // vector<int> initArr = arr;
    // sort(arr.begin(), arr.end());
    // do{
    //   allPermutations.push_back(arr);
    // } while(next_permutation(arr.begin(), arr.end()));
    // for(int i = 0; i < n-1; i++){
    //   if(allPermutations[i] == initArr){
    //     return allPermutations[i+1];
    //   }
    // }
    // return allPermutations[0];

    int idx = -1;
    for(int i = n -2; i >= 0; i--){
      if(arr[i] < arr[i+1]){
        idx = i;
        break;
      }
    }
    if(idx == -1) {
      reverse(arr.begin(), arr.end());
      return arr;
    }
    for(int i = n - 1; i > idx; i--){
      if(arr[i] > arr[idx]){
        swap(arr[i], arr[idx]);
        break;
      }
    }
    reverse(arr.begin()+idx+1, arr.end());
    return arr;
  }
};

int main() {
  vector<int> arr = {1,3,2}; // Output: {2,1,3}
  // arr = {3,2,1}; // Output: {1, 2, 3}
  arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 15, 14, 12, 11, 10}; // [1, 2, 3, 4, 5, 6, 7, 8, 9, 14, 10, 11, 12, 13, 15]

  Solution sl;
  for(int e: sl.nextPermutation(arr)){
    cout<<e<<" ";
  }
  return 0;
}