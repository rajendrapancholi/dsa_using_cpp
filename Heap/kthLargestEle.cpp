/* Kth largest element in a stream of running integers
Problem Statement: Implement a class KthLargest to find the kth largest number in a stream. It should have the following methods:

KthLargest(int k, int [] nums) Initializes the object with the integer k and the initial stream of numbers in nums
int add(int val) Appends the integer val to the stream and returns the kth largest element in the stream.
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Examples
Input: [KthLargest(3, [1, 2, 3, 4]), add(5), add(2), add(7)]
Output: [null, 3, 3, 4]
Explanation: initial stream = [1, 2, 3, 4], k = 3.
add(5): stream = [1, 2, 3, 4, 5] -> returns 3
add(2): stream = [1, 2, 2, 3, 4, 5] -> returns 3
add(7): stream = [1, 2, 2, 3, 4, 5, 7] -> returns 4

Input: [KthLargest(2, [5, 5, 5, 5], add(2), add(6), add(60)]
Output: [null, 5, 5, 6]
Explanation: initial stream = [5, 5, 5, 5], k = 2.
add(2): stream = [5, 5, 5, 5, 2] -> returns 5
add(6): stream = [5, 5, 5, 5, 2, 6] -> returns 5
add(60): stream = [5, 5, 5, 5, 2, 6, 60] -> returns 6
*/

#include <bits/stdc++.h>

using namespace std;

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<>> pq;
  int kk;
public:
  KthLargest(int k, vector<int> &nums){
    kk = k;
    for(int i = 0; i  < nums.size(); i++){
      pq.push(nums[i]);
      if(pq.size() > k) pq.pop();
    }

    cout<<"null"<<", ";
  }
  int add(int e){
    if(pq.top() < e){
      pq.pop();
      pq.push(e);
    }
    return pq.top();
  }
};

int main() {
  // Input: [KthLargest(3, [1, 2, 3, 4]), add(5), add(2), add(7)]
  // Output: [null, 3, 3, 4]
  // vector<int> nums = {1, 2, 3, 4};

  // Input: [KthLargest(2, [5, 5, 5, 5], add(2), add(6), add(60)]
  // Output: [null, 5, 5, 6]
  vector<int> nums = {5, 5, 5, 5};
  int k = 2;
  KthLargest kl(k, nums);
  cout<<kl.add(2)<<", ";
  cout<<kl.add(6)<<", ";
  cout<<kl.add(60)<<endl;
  return 0;
}
