#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // Binary search on the smaller array
        if (a.size() > b.size()) {
            return kthElement(b, a, k);
        }

        int n = a.size();
        int m = b.size();

        // Number of elements taken from a:
        // low <= cutA <= high
        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {
            int cutA = low + (high - low) / 2;
            int cutB = k - cutA;

            int leftA  = (cutA == 0) ? INT_MIN : a[cutA - 1];
            int rightA = (cutA == n) ? INT_MAX : a[cutA];

            int leftB  = (cutB == 0) ? INT_MIN : b[cutB - 1];
            int rightB = (cutB == m) ? INT_MAX : b[cutB];

            // Valid partition
            if (leftA <= rightB && leftB <= rightA) {
                return max(leftA, leftB);
            }

            // Too many elements selected from a
            if (leftA > rightB) {
                high = cutA - 1;
            } else {
                // Too few elements selected from a
                low = cutA + 1;
            }
        }

        return -1; // Invalid input
    }
};
