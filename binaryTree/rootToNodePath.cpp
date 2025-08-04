/**********************
Program Name        : Print Root to Node Path
Author              : Rajendra Pancholi
Date of creation    : 03/08/2025
Organization        : NIT Patna
***********************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution{
    public:

    bool getPath(TreeNode* root, vector<int>& ans, int& x){
        if(root==nullptr) return false;
        
        ans.push_back(root->val);
        if (root->val == x) {
            return true;
        }
        if (getPath(root->left, ans, x)
            || getPath(root->right, ans, x)) {
            return true;
        }
        ans.pop_back();
        return false;
    }


    vector<int> printRoot2NodePath(TreeNode* root, int& x){
        vector<int> ans;
        if( root==nullptr) return ans;
        getPath(root, ans, x);
        return ans;
    }

};



int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);
    Solution tree;
    int x = 7;
    vector<int> path=tree.printRoot2NodePath(root, x);
    for(auto x: path)
        cout<<x<<" ";
    return 0;
}