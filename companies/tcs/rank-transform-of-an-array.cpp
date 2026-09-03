#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    if (arr.empty())
      return {};
    vector<int> sortedArr = arr; // copy
    unordered_map<int, int> map;
    sort(sortedArr.begin(), sortedArr.end()); // Sort
    int rank = 1;
    for (int num : sortedArr) {
      if (map.find(num) == map.end()) {
        map[num] = rank;
        rank++;
      }
    }
    for (int i = 0; i < arr.size(); i++) {
      sortedArr[i] = map[arr[i]];
    }

    return sortedArr;
  }
};

int main() {
  vector<int> arr = {40, 10, 20, 30};
  Solution sl;
  for (int el : sl.arrayRankTransform(arr)) {
    cout << el << ' ';
  }

  return 0;
}
