/* Convert Min Heap to Max Heap
Given a min-heap in array representation named nums, convert it into a max-heap and return the resulting array.
A min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in the Binary Tree.
A max-heap is a complete binary tree where the key at the root is the maximum among all keys present in a binary max-heap and the same property is recursively true for all nodes in the Binary Tree.
Since there can be multiple answers, the compiler will return true if it's correct, else false.

Example 1
Input: nums = [10, 20, 30, 21, 23]
Output: [30, 21, 23, 10, 20]
Explanation:
In the input min heap, 10 is the root (smallest).
After conversion, 30 becomes the root (largest).
Now every parent node is larger than its children:
30 > 21, 30 > 23
21 > 10, 23 > 20
Hence it is a valid max heap.

Example 2
Input: nums = [-5, -4, -3, -2, -1]
Output: [-1, -2, -3, -4, -5]
Explanation:
In the input min heap, -5 is the root (smallest among negatives).
After conversion, -1 becomes the root (largest among negatives).
Now every parent node is larger than its children:
-1 > -2, -1 > -3
-2 > -4, -3 > -5
Hence it is a valid max heap.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void maxHeapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && nums[left] > nums[largest]) {
      largest = left;
    }
    if (right < n && nums[right] > nums[largest]) {
      largest = right;
    }
    if (largest != i) {
      swap(nums[i], nums[largest]);
      maxHeapify(nums, n, largest);
    }
  }
public:
  vector<int>& convertMinToMaxHeap(vector<int>& nums) {
    int n = nums.size();
    for (int i = (n / 2) - 1; i >= 0; --i) {
      maxHeapify(nums, n, i);
    }
    return nums;
  }
};

int main() {
  vector<int> nums = {10, 20, 30, 21, 23};
  Solution sl;
  for(auto it: sl.convertMinToMaxHeap(nums)) {
    cout<<it<<' ';
  }
  cout<<endl;
  return 0;
}

