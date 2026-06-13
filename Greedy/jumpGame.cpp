/* Jump Game
Given an array where each element represents the maximum number of steps you can jump forward from that element, return true if we can reach the last index starting from the first index. Otherwise, return false.

Examples
Example 1:
Input:nums = [2, 3, 1, 0, 4]
Output: True           
Explanation: 
We start at index 0, with value 2 this means we can jump to index 1 or 2.
From index 1, with value 3, we can jump to index 2, 3, or 4. However, if we jump to index 2 with value 1, we can only jump to index 3.
So we jump to index 1 then index 4 reaching the end of the array.
Hence, we return true.

Example 2:
Input:nums = [3, 2, 1, 0, 4]
Output: False
Explanation: 
We start at index 0, with value 3 which means we can jump to index 1, 2, or 3.
From index 1, with value 2 we can only jump to index 2 or 3.
From index 2, with value 1 we can only jump to index 3.
From index 3, with value 0 we cannot jump any further.
Hence, from all possibilities we are unable to jump to the last index so we return false.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums){
    int mxi = 0;
    for(int i = 0; i < nums.size(); i++){
      if(i > mxi) return false;
      mxi = max(mxi, i + nums[i]);
      if (mxi >= nums.size() - 1) return true; 
    }

    return true;
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 0, 4};
  Solution sl;
  cout<<(sl.canJump(nums)? "True" : "False")<<endl;
  return 0;
}
