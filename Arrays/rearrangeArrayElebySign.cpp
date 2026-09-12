/* Rearrange Array Elements by Sign
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative
elements. Without altering the relative order of positive and negative elements,
you must return an array of alternately positive and negative values.

Examples
Example 1:
Input:
arr[] = {1,2,-4,-5}, N = 4
Output:
1 -4 2 -5
Explanation:
Positive elements = 1,2
Negative elements = -4,-5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before
-5.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArrayElebySign(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    int posIndex = 0, negIndex = 1;

    for (int i = 0; i < n; i++) {
      if (arr[i] > 0) {
        ans[posIndex] = arr[i];
        posIndex += 2;
      } else {
        ans[negIndex] = arr[i];
        negIndex += 2;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> arr = {4, -1, -2, 5};
  arr = {-4, -1, 2, 5};
  int N = 4; // 1 -4 2 -5
  Solution sl;
  
  for (auto it : sl.rearrangeArrayElebySign(arr)) {
    cout << it << " ";
  }

  return 0;
}