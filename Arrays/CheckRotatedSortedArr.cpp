// Check if an Array is Sorted

// Input: N = 5, array[] = {1,2,3,4,5}
// Output: True.
// Input: N = 5, array[] = {5,4,6,7,8}
// Output: False.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(vector<int>& arr){
    int count = 0, n = arr.size();
    for(int i = 0; i < n; i++){
      if(arr[i] > arr[(i + 1) % n]){
        count++;
      }
      if(count > 1) return false;
    }
    return true;
  }
};

int main(){
  vector<int> arr = {3,4,5,1,2};
  Solution sl;
  cout<<(sl.check(arr) ? "True": "False")<<endl;
  return 0;
}