/* Accounts Merge - DSU: 
Problem Statement: Merge accounts that share common emails and return each user’s name followed by their sorted, unique emails.
Input: N = 6
accounts [ ] =
    [["John","j1@com","j2@com","j3@com"],
    ["John","j4@com"],
    ["Raj",”r1@com”, “r2@com”],
    ["John","j1@com","j5@com"],
    ["Raj",”r2@com”, “r3@com”],
    ["Mary","m1@com"]]

Output: [["John","j1@com","j2@com","j3@com","j5@com"],
        ["John","j4@com"],
        ["Raj",”r1@com”, “r2@com”,  “r3@com”],
        ["Mary","m1@com"]]
*/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size, rank;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        for (int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUlParent(int node){ // finding ultimate parent.
        if(node == parent[node]) return parent[node];
        return parent[node] = findUlParent(parent[node]);
    }
    void unionBySize(int x, int y){
        int ulp_x = findUlParent(x);
        int ulp_y = findUlParent(y);
        if(ulp_x == ulp_y) return;
        if(size[ulp_x]<size[ulp_y]){
            parent[ulp_x] = ulp_y;
            size[ulp_y]+= size[ulp_x];
        } else {
            parent[ulp_y] = ulp_x;
            size[ulp_x]+= size[ulp_y];
        }
    }
    void unionByRank(int x, int y){
        int ulp_x = findUlParent(x);
        int ulp_y = findUlParent(y);
        if(ulp_x == ulp_y) return;
        if(rank[ulp_x]<rank[ulp_y]) parent[ulp_x] = ulp_y;
        else if(rank[ulp_y]<rank[ulp_x]) parent[ulp_y] = ulp_x;
        else{
            parent[ulp_x] = ulp_y;
            rank[ulp_x]++;
       }
    }
};


class Solution{
    public:
    vector<vector<string>> mergeAccount(vector<vector<string>>& accounts){
        vector<vector<string>> result;
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailNode;

        for (int i = 0; i < n; i++){
            for (int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                auto isPresent = emailNode.find(email);
                if(isPresent == emailNode.end()){
                    emailNode[email] = i;
                } else {
                    dsu.unionBySize(i, emailNode[email]);
                }
            }
            
        }
        
        // Group emails to its ultimate parent
        vector<string> mergedMail[n];
        for (auto it : emailNode) {
            string mail = it.first;
            int node = dsu.findUlParent(it.second);
            mergedMail[node].push_back(mail);
        }
        
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            result.push_back(temp);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main(){
    vector<vector<string>> accounts = {
        {"John","j1@com","j2@com","j3@com"},
        {"John","j4@com"},
        {"Raj","r1@com", "r2@com"},
        {"John","j1@com","j5@com"},
        {"Raj","r2@com", "r3@com"},
        {"Mary","m1@com"}};
    Solution sl;
    for(auto it: sl.mergeAccount(accounts)){
        cout<<'[';
        for(auto i: it){
             cout<<i<<", ";
        } cout<<']'<<endl;
    }
    

    return 0;
}