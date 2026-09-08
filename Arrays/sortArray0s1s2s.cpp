// Sort an array of 0s, 1s and 2s
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int sortArr(vector<int>& nums) {
    int l = 0, m = 0, h = nums.size()-1;
    while(m <= h){
      if(nums[m] == 0) swap(nums[m++], nums[l++]);
      else if(nums[m] == 1) m++;
      else swap(nums[m], nums[h--]);
    }
    return 0;
  }
};

int main() {
  vector<int> nums = {1, 0, 2, 1, 0};
  // Output: [0, 0, 1, 1, 2]
  Solution sl;
  sl.sortArr(nums);
  for (auto it : nums) {
    cout << it << " ";
  }
  return 0;
}