/* Check if an array represents a min heap
Given an array of integers nums. Check whether the array represents a binary min-heap or not. Return true if it does, otherwise return false.
A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

Examples
Input: nums = [10, 20, 30, 21, 23]
Output: true
Explanation: Each node has a lower or equal value than its children.


Input: nums = [10, 20, 30, 25, 15]
Output: false
Explanation: The node with value 20 has a child with value 15, thus it is not a min-heap.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isMinHeap(vector<int> &nums){
    int n = nums.size();
    for(int i = 0; i < (n / 2); i++){
      int l = 2 * i + 1;
      if(l < n && nums[i] > nums[l])
        return false;
      int r = 2 * i + 2;
      if(l < n && nums[i] > nums[r])
        return false;
    }
    return true;
  }
};

int main() {
  vector<int> nums1 = {10, 20, 30, 21, 23}; // Output: true
  vector<int> nums2 = {10, 20, 30, 25, 15}; // Output: false
  Solution sl;
  cout<<sl.isMinHeap(nums1)<<endl;
  cout<<sl.isMinHeap(nums2)<<endl;
  return 0;
}
