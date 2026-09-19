/* Trapping Rainwater
Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain .

Examples

Input : height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output : 6
Explanation : Water is trapped in the dips between bars. The total trapped water units add up to 6 (1+1+2+1+1).

Input : height = [4,2,0,3,2,5]
Output : 9
Explanation : The elevation map traps 9 units of water in total, as water fills the spaces between higher bars on both sides. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trappingRainwaterM1(vector<int>& height) { // TC = O(n²), SC = O(1);
    int n = height.size(), ans = 0;
    for(int i = 0; i < n; i++){
      int leftMx = 0, rightMx = 0;
      for(int j  = 0; j <= i; j++) leftMx = max(leftMx, height[j]);
      for(int j  = i; j < n; j++) rightMx = max(rightMx, height[j]);
      ans += min(leftMx, rightMx) - height[i];
    }
    return ans;
  }

  int trappingRainwaterM2(vector<int>& height) { // TC = O(n), SC = O(1);
    int n = height.size(), ans = 0;
    int leftMx = 0, rightMx = 0, left = 0, right = n - 1;
    while(left <= right){
      leftMx = max(leftMx, height[left]);
      rightMx = max(rightMx, height[right]);
      if(height[left] < height[right]){
        ans += min(leftMx, rightMx) - height[left];
        left++;
      } else{
        ans += min(leftMx, rightMx) - height[right];
        right--;
      }
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int>  height = {0,1,0,2,1,0,1,3,2,1,2,1}; // 6
  
  Solution sl;
  auto result = sl.trappingRainwaterM1(height);
  cout << result << "\n\n";
  result = sl.trappingRainwaterM2(height);
  cout << result << "\n";
  
  return 0;
}
