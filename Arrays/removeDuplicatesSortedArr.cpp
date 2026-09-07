// Remove Duplicates in-place from Sorted Array

// Input: arr[]=[1,1,2,2,2,3,3]
// Output: [1,2,3,_,_,_,_]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDup(vector<int> &arr) {
    if(arr.empty()) return 0;
    int insertIdx = 1;
    for(int i = 1; i < arr.size(); i++){
      if(arr[i] != arr[i - 1]){
        arr[insertIdx] = arr[i];
        insertIdx++;
      }
    }
    return insertIdx;
  }
};

int main() {
  vector<int> arr = {1, 1, 2, 2, 2, 3, 3}; // [1,2,3,_,_,_,_]
  Solution sl;
  int counter = sl.removeDup(arr);
  for(int i = 0; i < counter; i++){
    cout<<arr[i]<< " ";
  }
  cout << endl;
  return 0;
}

