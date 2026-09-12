/* Leaders in an Array
Input:
 arr = [4, 7, 1, 0]  
Output:
 7 1 0  
Explanation:
 The rightmost element (0) is always a leader.  
7 and 1 are greater than the elements to their right, making them leaders as well.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]  
Output:
 22 12 6  
Explanation:
 6 is a leader because there are no elements after it.  
12 is greater than all the elements to its right (3, 0, 6), and 22 is greater than 12, 3, 0, 6, making them leaders as well. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> leaderInAnArray(vector<int>& arr) {
    if(arr.empty()) return {};
    int n = arr.size(); 
    vector<int> leaders;
    // for(int i  = 0; i < n - 1; i++){ // TC O(n^2)
    //   if(arr[i] > *max_element(arr.begin()+i+1, arr.end())){
    //     leaders.push_back(arr[i]);
    //   }
    // }
    // leaders.push_back(arr[n-1]);
    
    int maxE = arr[n-1];
    leaders.push_back(maxE);

    for(int i = n -2; i >= 0; i--){ // TC O(n)
      if(arr[i] > maxE){
        leaders.push_back(arr[i]);
        maxE = arr[i];
      }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
  }
};

int main() {
// Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> arr = {4, 7, 1, 0}; // Output:[ 7 1 0 ]
  arr = {10, 22, 12, 3, 0, 6}; // Output: 22 12 6
  
  Solution sol;
  auto result = sol.leaderInAnArray(arr);
  
  for(int el: result){
    cout<<el<<" ";
  }
  
  return 0;
}