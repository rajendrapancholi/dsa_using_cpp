/* Find Median from Data Stream
Implement a class that finds the median from a data stream. The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
Implement the MedianFinder class as follows:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

Examples
  Input : [MedianFinder(), addNum(1), addNum(2), addNum(3), findMedian()]
  Output : [null, null, null, null, 2]
  Explanation : MedianFinder() initializes the object. addNum(1) adds 1 to the data stream → [1] addNum(2) adds 2 → [1, 2] addNum(3) adds 3 → [1, 2, 3] findMedian() returns 2 as the median of [1, 2, 3]

  Input : [MedianFinder(), addNum(1), addNum(6), findMedian(), addNum(3), findMedian()]
  Output : [null, null, null, 3.5, null, 3]
  Explanation : MedianFinder() initializes the object. addNum(1) → [1] addNum(6) → [1, 6] findMedian() returns (1+6)/2 = 3.5 addNum(3) → [1, 3, 6] findMedian() returns 3 as the median
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

public:
  MedianFinder() {
  }
  void addNum(int num) {
    maxHeap.push(num);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian() {
    if (maxHeap.size() == minHeap.size()) {
      return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    return maxHeap.top();
  }
};

int main() {
  MedianFinder mf;
  mf.addNum(1);
  cout << mf.findMedian() << endl;
  mf.addNum(2);
  cout << mf.findMedian() << endl; // Output: 1.5
  mf.addNum(3);
  cout << mf.findMedian() << endl; // Output: 2
  return 0;
}
