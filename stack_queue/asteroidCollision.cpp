#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> st;

        for (int i = 0; i < a.size(); i++) {
            while (!st.empty() && st.back() > 0 && a[i] < 0) {
                if (st.back() < abs(a[i])) {
                    st.pop_back();
                    continue;
                } else if (st.back() == abs(a[i])) {
                    st.pop_back();
                }
                goto destroyed; 
            }
            st.push_back(a[i]);
            destroyed:;
        }
        return st;
    }
};
int main() {
    vector<int> asteroids = {10, 2, -5};
    Solution sol;
    vector<int> answer = sol.asteroidCollision(asteroids);

    for (int value : answer) {
        cout << value << " ";
    }
    return 0;
}