/* Fruit Into Baskets
Problem Statement: There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.
The goal is to gather as much fruit as possible, adhering to the owner's stringent rules :

There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
Once reaching a tree with fruit that cannot fit into any basket, stop.
Return the maximum number of fruits that can be picked.

Examples
Input :fruits = [1, 2, 1]
Output :3
Explanation : We will start from first tree.
The first tree produces the fruit of kind '1' and we will put that in the first basket.
The second tree produces the fruit of kind '2' and we will put that in the second basket.
The third tree produces the fruit of kind '1' and we have first basket that is already holding fruit of kind '1'. So we will put it in first basket.
Hence we were able to collect total of 3 fruits.

Input : fruits = [1, 2, 3, 2, 2]
Output : 4
Explanation : we will start from second tree.
The first basket contains fruits from second , fourth and fifth.
The second basket will contain fruit from third tree.
Hence we collected total of 4 fruits.
*/

#include <iostream>
#include <vector>
#include <set>
#include<unordered_map>

using namespace std;

class Solution {
public:
  // Brute force method TC = O(n^2)
  int findMaxPickedFruit(vector<int> &fruits){
    int n = fruits.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++){
      set<int> st;
      for(int j = i; j < n; j++){
        st.insert(fruits[j]);
        if(st.size() <= 2){
          maxLen = max(maxLen, j - i + 1);
        } else 
          break;
      }
    }
    return maxLen;
  }
  // Optimize method using sliding window TC = O(n^2) -> O(n)
  int findMaxPickedFruitSW(vector<int> &fruits){
    int n = fruits.size(), maxLen = 0;
    int left = 0;
    unordered_map<int, int> mpp; 
    
    for(int right = 0; right < n; right++){
      while(mpp.size() > 2){
        mpp[fruits[left]]--; 
        
        if(mpp[fruits[left]] == 0){
          mpp.erase(fruits[left]); 
        }
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }

};

int main() {
  // vector<int> fruits = {1, 2, 1};
  vector<int> fruits = {1, 2, 3, 2, 2};
  Solution sl;
  cout<<sl.findMaxPickedFruit(fruits)<<endl;
  cout<<sl.findMaxPickedFruitSW(fruits)<<endl;
  return 0;
}
