/* Union of Two Sorted Arrays

Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find
the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in
the two arrays.

NOTE: Elements in the union should be in ascending order.

Examples

Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}

Input:n = 10,m = 7,arr1[] = {1,2,3,4,5,6,7,8,9,10}arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortedArr(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size(), m = arr2.size(), i = 0, j = 0;
    vector<int> sortedA;

    while (i < n && j < m) {
      if (arr1[i] < arr2[j]) {
        sortedA.push_back(arr1[i++]);
        while (i < n && arr1[i - 1] == arr1[i]) {
          i++;
        }
      } else if (arr1[i] > arr2[j]) {
        sortedA.push_back(arr2[j++]);
        while (j < m && arr2[j - 1] == arr2[j]) {
          j++;
        }
      } else {
        sortedA.push_back(arr1[i]);
        int val = arr1[i];

        while (i < n && arr1[i] == val)
          i++;
        while (j < m && arr2[j] == val)
          j++;
      }
    }

    while (i < n) {
      if (sortedA.empty() || sortedA.back() != arr1[i]) {
        sortedA.push_back(arr1[i]);
      }
      i++;
    }

    while (j < m) {
      if (sortedA.empty() || sortedA.back() != arr2[j]) {
        sortedA.push_back(arr2[j]);
      }
      j++;
    }

    return sortedA;
  }
};

int main() {
  vector<int> arr1 = {1, 2, 3, 4, 5, 7, 10, 15, 16};
  vector<int> arr2 = {2, 3, 4, 4, 5, 7, 22, 33};
  Solution sl;
  for (int it : sl.sortedArr(arr1, arr2)) {
    cout << it << " ";
  }
  return 0;
}