/* Union of Two Sorted Arrays*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortedArr(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size(), m = arr2.size(), i = 0, j = 0;
    set<int> st;
    for(int e: arr1){
      st.insert(e);
    }
    for(int e: arr2){
      st.insert(e);
    }
    vector<int> sortedA(st.begin(), st.end());
    
    return sortedA;
  }
};

int main() {
  vector<int> arr1 = {1, 2, 3, 4, 5, 7, 10, 15, 16};
  vector<int> arr2 = {2, 3, 4, 4, 5, 7, 22};
  Solution sl;
  for (int it : sl.sortedArr(arr1, arr2)) {
    cout << it << " ";
  }
  return 0;
}