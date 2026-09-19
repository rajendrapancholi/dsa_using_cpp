/* Previous Greater Element Using Stack
Given an integer array A, return the previous greater element for every element in A. The previous greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

Examples
Input: arr = [4, 2, 3, 1]
Output: [-1, 4, 4, 1]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> previousGreaterElement(vector<int>& arr) { // TC = O(n), SC = O(n);
        vector<int> ans(arr.size(), -1);
        stack<int> st;
        for(int i = 0; i < arr.size(); i++) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }

    vector<int> previousSmallerElement(vector<int>& arr) { // TC = O(n), SC = O(n);
        vector<int> ans(arr.size(), -1);
        stack<int> st;
        for(int i = 0; i < arr.size(); i++) {
            while (!st.empty() && st.top() > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};

int main() {
    // Fast I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {4, 2, 3, 1}; // Output: [3, 4, 4, -1]
    Solution sl;
    auto result = sl.previousGreaterElement(arr);

    for (auto r : result) {
        cout << r << " ";
    }

    cout<<"\n\n";
    arr = {4, 2, 3, 1}; // -1 -1 2 -1 
    arr = {1, 3, 2, 4}; // -1 1 1 2 
    result = sl.previousSmallerElement(arr);

    for (auto r : result) {
        cout << r << " ";
    }
    
    return 0;
}
