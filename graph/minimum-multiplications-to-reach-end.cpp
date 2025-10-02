/* Minimum Multiplications to Reach End
Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and then a mod operation with 100000 is done to get the new start.
Your task is to find the minimum steps in which the end can be achieved starting from the start. If it is not possible to reach the end, then return -1.
Example 2:
Input:
arr[] = {2, 5, 7}
start = 3
end = 30
Output: 2
Explanation: 
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
Therefore, in minimum 2 multiplications we reach the 
end number which is treated as a destination 
node of a graph here.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumMul(vector<int> &arr, int start, int end){
        queue<pair<int, int>> q; // {mult, steps}
        int mod = 1e5;
        vector<int> dist(mod, 1e9);
        q.push({start, 0});
        dist[start]=0;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(auto it: arr){
                int num = (it*node) % mod;
                if (steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {2,5,7};
    int start = 3, end = 30;
    Solution sl;
    cout<<sl.minimumMul(arr, start, end)<<endl;
    cout<<"Start: "<<start<<endl;
    cout<<"End: "<<end<<endl;
    return 0;
}





