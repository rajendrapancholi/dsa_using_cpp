/* Sort K sorted array
Given an array arr[] and a number k . The array is sorted in a way that every element is at max k distance away from it sorted position. It means if we completely sort the array, then the index of the element can go from i - k to i + k where i is index in the given array. Our task is to completely sort the array.

Examples
Input :  arr = [6, 5, 3, 2, 8, 10, 9], k = 3
Output :  [2, 3, 5, 6, 8, 9, 10]
Explanation :  The element 2 was at index 3, it moved to index 0. The element 3 was at index 2, it moved to index 1. The element 5 moved from index 1 to index 2. The element 6 moved from index 0 to index 3. The rest (8, 9, 10) were near their correct spots and shifted slightly.

Input :  arr = [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output :  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation :  The element 2 moved from index 3 to index 1. The element 3 moved from index 4 to index 2. The element 4 moved from index 1 to index 3. The element 5 moved from index 2 to index 4. All others remained in or near their correct positions.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  vector<int> ksorted(vector<int> &arr, int k){
    priority_queue<int, vector<int>, greater<int>> pq; // minHeap priority queue
    vector<int> res;
    for(int i = 0; i <= k && i < arr.size(); i++){
      pq.push(arr[i]);
    }
    for(int i = k + 1; i < arr.size(); i++){
      res.push_back(pq.top());
      pq.pop();
      pq.push(arr[i]);
    }
    while(!pq.empty()){
      res.push_back(pq.top());
      pq.pop();
    }
    return res;
  }
};

int main() {
  vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
  int k = 3; // Output :  [2, 3, 5, 6, 8, 9, 10]
  Solution sl;
  for(auto it: sl.ksorted(arr, k)) {
    cout<<it<<", ";
  } 
  return 0;
}

