/* Longest Subarray with sum K | [Postives and Negatives]
 Given an array and a sum k, we need to print the length of the longest subarray
that sums to k.

Examples
Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 3, k = 1, array[] = {-1, 1, 1}
Result: 3
Explanation: The longest subarray with sum 1 is {-1, 1, 1}. And its length is 3.
*/
#include <bits/stdc++.h>
using namespace std;

class SubarraySolver {
public:
  int getLongestSubarray(vector<int> &a, int k) {
    int n = a.size();
    map<int, int> preSumMap;
    preSumMap[0] = -1;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
      sum += a[i];
      int rem = sum - k;
      if (preSumMap.find(rem) != preSumMap.end()) { // if rem found calculate len
        maxLen = max(maxLen, i - preSumMap[rem]);
      }
      if (preSumMap.find(sum) == preSumMap.end()) { // if rem not found add into map
        preSumMap[sum] = i;
      }
    }
    return maxLen;
  }
};

int main() {
  vector<int> a = {1, 1, -1};
  int k = 1;

  SubarraySolver solver;
  int len = solver.getLongestSubarray(a, k);

  cout << "" << len << "\n";
  return 0;
}
