/* Find Building Where Alice and Bob Can Meet
You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.
If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].
You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.
Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

Example 1:

Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
Output: [2,5,-1,5,2]
Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2]. 
In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5]. 
In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
In the fifth query, Alice and Bob are already in the same building.  
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
Example 2:

Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
Output: [7,6,-1,4,6]
Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

Constraints:
1 <= heights.length <= 5 * 104
1 <= heights[i] <= 109
1 <= queries.length <= 5 * 104
queries[i] = [ai, bi]
0 <= ai, bi <= heights.length - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void buildST(int i, int start, int end, int st[], vector<int>& h) {
        if(start == end){
            st[i] = start;
            return;
        }
        int mid = start + (end - start)/2;

        buildST(2*i, start, mid, st, h);
        buildST(2*i+1, mid+1, end, st, h);
        
        int l_idx = st[2*i];
        int r_idx = st[2*i+1];
        st[i] = (h[l_idx] >= h[r_idx])? l_idx: r_idx;
    }

    int* constructST(vector<int>& h, int n) {
        int* st = new int[4*n];
        buildST(1, 0, n-1, st, h);        
        return st;
    }

    int queryST(int l, int r, int i, int start, int end, int st[], vector<int>& h) {
        if(l > end || r < start){
            return -1;
        }
        if(start>=l && end<=r){
            return st[i];
        }
        int mid = start + (end - start)/2;
        int l_idx = queryST(l, r, 2*i, start, mid, st, h);
        int r_idx = queryST(l, r, 2*i+1, mid+1, end, st, h);
        if(l_idx == -1) return r_idx;
        if(r_idx == -1) return l_idx;
        return (h[l_idx] >= h[r_idx])? l_idx: r_idx;
    }   

    int RMIQ(int st[], vector<int>& h, int n, int l, int r) {
        return queryST(l, r, 1, 0, n-1, st, h);
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& queries) {
        int n=h.size();
        int* st = constructST(h, n);
        vector<int> ans;
        for(auto &q: queries){ // O(n)
            int mnIdx=min(q[0], q[1]);
            int mxIdx=max(q[0], q[1]);
            if(mnIdx==mxIdx){
                ans.push_back(mnIdx);
                continue;
            } else if(h[mnIdx] < h[mxIdx]){
                ans.push_back(mxIdx);
                continue;
            }
            int l=mxIdx+1;
            int r=n-1;
            int ansIdx=INT_MAX;
            while(l<=r){ // O(log(n))
                int mid=l+(r-l)/2;
                int idx=RMIQ(st, h, n, l, mid); // O(log(n))
                if(h[idx] > max(h[mnIdx], h[mxIdx])) ansIdx=min(ansIdx, idx), r=mid-1;
                else l=mid+1;
            }
            (ansIdx == INT_MAX) ? ans.push_back(-1) : ans.push_back(ansIdx); 
        }
        delete[] st;
        return ans;
    }
};

int main() {
    // Fast I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> heights = {6,4,8,5,2,7}; 
    vector<vector<int>> queries = {{0,1}, {0,3}, {2,4}, {3,4}, {2,2}};
    Solution sl;
    // Output: [2,5,-1,5,2]
    for(auto el: sl.leftmostBuildingQueries(heights, queries)){
        cout<<el<<" ";
    }
    cout<<"\n";
    
    return 0;
}