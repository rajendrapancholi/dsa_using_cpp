/* Fractional Knapsack Problem : Greedy Approach
The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

Examples
Example 1:
Input:
 val = [60, 100, 120], wt = [10, 20, 30], capacity = 50  
Output:
 240.000000  
Explanation:
  
- Take item 0 (w = 10, v = 60)  
- Take item 1 (w = 20, v = 100)  
- Take 2⁄3 of item 2 (w = 20, v = 80)  
Total value = 60 + 100 + 80 = 240

Example 2:
Input:
 val = [60, 100], wt = [10, 20], capacity = 50  
Output:
 160.000000  
Explanation:
  
Both items fit entirely since total weight 10 + 20 = 30 ≤ 50.  
Total value = 60 + 100 = 160
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  struct Item {
    int val;
    int wt;
  };
public:
  static bool comparator(Item a, Item b){
    return (double)(a.val / a.wt) > (double)(b.val / b.wt);
  }
  
  int totalValueKS(int val[], int wt[], int cp, int n){
    Item arr[n];
    for(int i = 0; i < n; i++)
      arr[i] = {val[i], wt[i]};
    sort(arr, arr + n, comparator);
    double ans = 0.0;
    for(int i = 0; i < n; i++){
      if(arr[i].wt <= cp){
        ans += arr[i].val;
        cp -= arr[i].wt;
      } else {
        ans += ((double)arr[i].val / arr[i].wt) * cp;
        break;
      }
    }
    return ans;
  }
};

int main() {
  // int  val[] = {60, 100, 120}, wt[] = {10, 20, 30}, capacity = 50;
  int val[] = {60, 100}, wt[] = {10, 20}, capacity = 50;
  int n = sizeof(val) / sizeof(val[0]);
  Solution sl;
  cout<<sl.totalValueKS(val, wt, capacity, n)<<endl;
  return 0;
}
