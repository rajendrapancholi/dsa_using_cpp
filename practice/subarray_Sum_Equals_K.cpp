#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int sum = 0, count = 0;
        freq[0] = 1;
        for(int el: nums){
            sum += el;
            if(freq.count(sum - k)) count += freq[sum - k];
            freq[sum]++;
        }
        return count;
    }
};