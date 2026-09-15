/* Count Reverse Pairs
Given an array of numbers, you need to return the count of reverse pairs.
Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

Examples
Example 1:
Input:
 N = 5, array[] = {1,3,2,3,1)
Output: 2
Explanation:
 The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] >
2*arr[j] is satisfied.

Example 2:
Input:
 N = 4, array[] = {3,2,1,4}
Output: 1
Explaination:
There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j] */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int merge(vector<int> &arr, int l, int mid, int r) {
    int count = 0;
    int j = mid + 1;

    for (int i = l; i <= mid; i++) {
      while (j <= r && (long long)arr[i] > 2 * (long long)arr[j]) {
        j++;
      }
      count += (j - (mid + 1));
    }

    int i = l;
    j = mid + 1;
    vector<int> temp;
    temp.reserve(r - l + 1);
    
    while (i <= mid && j <= r) {
      if (arr[i] <= arr[j])
        temp.push_back(arr[i++]);
      else {
        temp.push_back(arr[j++]);
      }
    }
    while (i <= mid)
      temp.push_back(arr[i++]);
    while (j <= r)
      temp.push_back(arr[j++]);

    for (int k = l; k <= r; k++)
      arr[k] = temp[k - l];

    return count;
  }
  int mergeSort(vector<int> &arr, int l, int r) {
    int count = 0;
    if (l >= r)
      return count;
    int mid = l + (r - l) / 2;
    count += mergeSort(arr, l, mid);
    count += mergeSort(arr, mid + 1, r);
    count += merge(arr, l, mid, r);

    return count;
  }

public:
  int countReversePairsM1(vector<int> &arr) { // TC = O(n^2), SC = O(1);
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        // i<j and arr[i]>2*arr[j].
        if (arr[i] > 2 * arr[j]) {
          count++;
        }
      }
    }
    return count;
  }
  int countReversePairsM2(vector<int> &arr) { // TC = O(nlogn), SC = O(n);
    return mergeSort(arr, 0, arr.size() - 1);
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> arr = {1, 3, 2, 3, 1}; // Output: 2
  // arr = {3,2,1,4}; // Output: 1

  Solution sl;
  cout << "method1 : ";
  auto result = sl.countReversePairsM1(arr);
  cout << result << "\n";

  cout << "method2 : ";
  result = sl.countReversePairsM2(arr);
  cout << result << "\n";

  return 0;
}
