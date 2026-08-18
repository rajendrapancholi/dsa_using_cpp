/* Print all the Unique Subsets
Given an integer array nums, which can have duplicate entries, provide the power set. Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.

Examples
Input: array[] = [1,2,2]
Output: [ [ ], [1], [1,2], [1,2,2], [2], [2,2] ]
Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]
Output: [ [ ], [1] ]
Explanation: Only two unique subsets are available.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
  void uniqSubsets(int i, vector<int> &arr, vector<int> temp, set<vector<int>> &ans) {
    if(i == arr.size()){
      ans.insert(temp);
      return;
    }
    temp.push_back(arr[i]);
    uniqSubsets(i + 1, arr, temp, ans);
    temp.pop_back();
    uniqSubsets(i + 1, arr, temp, ans);
  }
};

int main() {
  vector<int> arr = {1, 2, 2};
  // Output: [ [ ], [1], [1,2], [1,2,2], [2], [2,2] ]

  Solution sl;
  set<vector<int>> ans;
  sl.uniqSubsets(0, arr, {}, ans);
  for(auto it: ans) {
    cout<<"[";
    for(auto e: it) {
      cout<<e<<",";
    }
    cout<<"]";
    cout<<endl;
  }
  return 0;
}
