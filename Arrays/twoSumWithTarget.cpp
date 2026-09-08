/* Two Sum : Check if a pair with given sum exists in Array
Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal
to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to
the target. Otherwise, we will return {-1, -1}.

Examples

Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
Output : YES
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for
second variant output will be : [1,3].

Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
Output : NO.
Explanation: There exist no such two numbers whose sum is equal to the target.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string twosk(vector<int> &arr, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++) {
      int rem = target - arr[i];
      if (map.count(rem)) {
        return "Yes";
      }
      map[arr[i]] = i;
    }
    return "No";
  }
};

int main() {
  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;
  Solution sl;
  cout << sl.twosk(arr, target) << endl;
  return 0;
}