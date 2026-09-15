/* Count inversions in an array
Given an array of N integers, count the inversion of the array (using
merge-sort).

Inversion of an array: for all i & j < size of array, if i < j then you have to
find pair (A[i],A[j]) such that A[j] < A[i].

Examples
Example 1:
Input Format: N = 5, array[] = {1,2,3,4,5}
Result: 0
Explanation: we have a sorted array and the sorted array has 0 inversions as for
i < j you will never find a pair such that A[j] < A[i]. More clear example: 2
has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.

Example 2:
Input Format: N = 5, array[] = {5,4,3,2,1}
Result: 10
Explanation: we have a reverse sorted array and we will get the maximum
inversions as for i < j we will always find a pair such that A[j] < A[i].
Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2
and 5 > 3 which will satisfy out conditions and for reverse sorted array we will
get maximum inversions and that is (n)*(n-1) / 2.For above given array there is
4 + 3 + 2 + 1 = 10 inversions.

Example 3:
Input Format: N = 5, array[] = {5,3,2,1,4}
Result: 7
Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1)
and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int merge(vector<int> &arr, int l, int mid, int r) {
    int count = 0;
    int i = l;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= r) {
      if (arr[i] <= arr[j]) {
        temp.push_back(arr[i]);
        i++;
      } else {
        temp.push_back(arr[j]);
        count += (mid - i + 1);
        j++;
      }
    }
    while (i <= mid) {
      temp.push_back(arr[i]);
      i++;
    }
    while (j <= r) {
      temp.push_back(arr[j]);
      j++;
    }
    for (int k = l; k <= r; k++) {
      arr[k] = temp[k - l];
    }
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
  int countinversionsM1(vector<int> &nums) { // tc => O(n^2), sc => O(1)
    int count = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] > nums[j]) {
          count++;
        }
      }
    }
    return count;
  }

  int countinversionsM2(vector<int> &nums) { // tc => O(nlogn), sc => O(n)
    return mergeSort(nums, 0, nums.size() - 1);
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> nums = {1, 2, 3, 4, 5};  // Result: 0
  vector<int> nums2 = {5, 3, 2, 1, 4}; // Result: 7

  Solution sl;
  auto result = sl.countinversionsM1(nums2);
  cout << result << "\n";

  result = sl.countinversionsM2(nums2);

  cout << result << "\n";

  return 0;
}