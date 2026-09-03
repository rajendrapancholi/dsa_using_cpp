// Find the Largest element in an array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestEl(vector<int> &arr) {
    if (arr.empty())
      return -1e9;

    int le = arr[0];
    for (int e : arr) {
      if (le < e)
        le = e;
    }
    return le;
  }
};

int main() {
  vector<int> arr = {2, 5, 1, 3, 0};
  Solution sl;
  cout << sl.largestEl(arr) << endl;
}