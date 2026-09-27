#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size(), cols = mat[0].size();
        int low = 0, high = rows*cols - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int r = mid/cols, c = mid%cols;
            if(mat[r][c] == target){
                return true;
            } else if(mat[r][c] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};