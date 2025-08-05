/**********************
Program Name        : Lowest Common Ancestor for two given Nodes
Author              : Rajendra Pancholi
Date of creation    : 04/08/2025
Organization        : NIT Patna
***********************/

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int v):val(v), left(nullptr), right(nullptr){}
    TreeNode(int v, TreeNode* l, TreeNode* r):val(v), left(l), right(r){}
};

class Solution{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int& p, int& q){
        if(root==nullptr || root->val==p || root->val==q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left==nullptr)
            return right;
        else if (right==nullptr)
            return left;
        else
            return root;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution sl;
    int p=4, q=5;
    TreeNode* lca = sl.lowestCommonAncestor(root, p,q);
    cout<<lca->val<<endl;

    return 0;
}