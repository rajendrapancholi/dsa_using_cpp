#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countOccurrences(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    int firtOcc = -1, lastOcc = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        firtOcc = mid;
        r = mid - 1; // searching in left
      } else if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        lastOcc = mid;
        l = mid + 1; // searching in right
      } else if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    cout << lastOcc << endl << firtOcc << endl;
    return (lastOcc == -1 && firtOcc == -1) ? 0 : lastOcc - firtOcc + 1;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arr = {2, 4, 6, 8, 10};
  int k = 3;
  Solution sl;
  auto result = sl.countOccurrences(arr, k);
  cout << result << "\n";

  return 0;
}