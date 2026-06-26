/* Replace elements by its rank in the array
Given an array of N integers, the task is to replace each element of the array by its rank in the array.

Examples
Input: 20 15 26 2 98 6
Output: 4 3 5 1 6 2
Explanation: When sorted,the array is 2,6,15,20,26,98. So the rank of 2 is 1,rank of 6 is 2,rank of 15 is 3 and so.

Input: 1 5 8 15 8 25 9
Output: 1 2 3 5 3 6 4
Explanation :When sorted,the array is 1,5,8,8,9,15,25. So the rank of 1 is 1,rank of 5 is 2,rank of 8 is 3 and so.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> replaceByRank(vector<int> &arr){
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> rankMap;
    int rank = 1;
    for (int num : sortedArr) {
      if (rankMap.find(num) == rankMap.end()) {
        rankMap[num] = rank;
        rank++;
      }
    }
    vector<int> result;
    for (int num : arr) {
      result.push_back(rankMap[num]);
    }
    return result;
  }
};

int main() {
  vector<int> arr = {20, 15, 26, 2, 98, 6}; // Output: 4 3 5 1 6 2

  Solution sl;
  vector<int> rank = sl.replaceByRank(arr);

  for(auto el: arr){
    cout<<el<<",\t";
  } cout<<endl;
  
  int i = 1;
  
  for(auto el: rank){
    cout<<el<<",\t";
  } cout<<endl;

  return 0;
}

