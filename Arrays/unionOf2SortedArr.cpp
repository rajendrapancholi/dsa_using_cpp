/* Union of Two Sorted Arrays*/

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
  vector<int> arr2 = {2, 3, 4, 4, 5, 7, 22};
  Solution sl;
  for (int it : sl.sortedArr(arr1, arr2)) {
    cout << it << " ";
  }
  return 0;
}