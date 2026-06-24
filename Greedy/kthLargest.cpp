/* Kth largest/smallest element in an array
Given an array nums, return the kth largest element in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargestElement(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        int left = 0, right = nums.size() - 1;
        while(true) {
            int pivotIndex = randomIndex(left, right);
            pivotIndex = partitionAndReturnIndex(nums, pivotIndex, left, right);
            if(pivotIndex == k-1) return nums[pivotIndex];
            else if(pivotIndex > k-1) right = pivotIndex - 1;
            else left = pivotIndex + 1;
        }
        return -1;
    }
private:
    int randomIndex(int &left, int &right) {
        int len = right - left + 1;
        return (rand() % len) + left;
    }
    
    int partitionAndReturnIndex(vector<int> &nums, int pivotIndex, int left, int right) {
        int pivot = nums[pivotIndex];
        swap(nums[left], nums[pivotIndex]);
        int ind = left + 1;
        for(int i = left + 1; i <= right; i++) {
            if(nums[i] > pivot) {
                swap(nums[ind], nums[i]);
                ind++;
            }
        }
        swap(nums[left], nums[ind-1]);
        return ind-1;
    }
};
int main() {
    vector<int> nums = {-5, 4, 1, 2, -3};
    int k = 5;
    Solution sol;
    int ans = sol.kthLargestElement(nums, k);
    cout << ans << endl;
    return 0;
}