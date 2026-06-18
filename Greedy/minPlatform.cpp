/* Minimum number of platforms required for a railway
We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

Input:  N=6, 
arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00}
dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}
Output: 3
Explanation: There are at-most three trains at a time. The train at 11:00 arrived but the trains which had arrived at 9:45 and 9:55 have still not departed. So, we need at least three platforms here.

Input : N=2, 
arr[]={10:20,12:00}
dep[]={10:50,12:30}
Output: 1
Explanation : Before the arrival of the new train, the earlier train already departed. So, we don't require multiple platforms.
*/

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
  int findMinPlatform(int N, vector<int> &arr, vector<int> &dep){
    int ans = 1;
    for(int i = 0; i < N; i++){
      int count = 1;
      for(int j = i + 1; j < N; j++){
        if(arr[i] >= arr[j] && arr[i] <= dep[j] || arr[j] >= arr[i] && arr[j] <= dep[i])
          count++;
      }
      ans = max(ans, count);
    }
    return ans;
  }

  int findMinPlatform2(int N, vector<int> &arr, vector<int> &dep){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0, j = 0;
    int platforms_needed = 0;
    int max_platforms = 0;
    while (i < N && j < N) {
      if (arr[i] <= dep[j]) {
        platforms_needed++;
        i++;
      } 
      else {
        platforms_needed--;
        j++;
      }
      max_platforms = max(max_platforms, platforms_needed);
    }
    return max_platforms;
  }

};

int main() {
  int N = 6;
  // vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
  // vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};
  N = 2;
  // vector<int> arr={1020, 1200};
  // vector<int> dep={1050, 1230};
  N = 3;
  vector<int> arr={900, 930, 1000};
  vector<int> dep={1030, 1300, 1015};
  
  Solution sl;
  cout<<sl.findMinPlatform(N, arr, dep)<<endl;
  cout<<sl.findMinPlatform2(N, arr, dep)<<endl;
  return 0;
}
