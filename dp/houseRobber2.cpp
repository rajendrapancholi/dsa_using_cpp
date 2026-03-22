#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int rob(vector<int>& arr, int start, int end){
    int prev2 = 0;
    int prev = 0;
    for(int i = start; i < end; i++){
      int pick = arr[i] + prev2;
      int notPick = prev;
      int curr = max(pick, notPick);
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
public:
  int mxPrhouseRobber2(vector<int>& arr){
    int n = arr.size();
    if(n==0) return 0;
    if(n==1) return arr[0];
    return max(rob(arr, 0, n-1), rob(arr, 1, n));
  }
};

int main() {
  vector<int> arr = {1,3,2,1};
  Solution sl;
  cout<<sl.mxPrhouseRobber2(arr)<<endl;
  return 0;
}
