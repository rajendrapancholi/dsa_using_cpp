// Count Number of Nodes in a Binary Tree
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r){}
};

class Solution{
    public:
    int countNodes(TreeNode* root){
        if(!root) return 0;
        int lft = leftHeight(root);
        int rgt = rightHeight(root);
        if(lft==rgt) return (1<<lft) - 1; // (2^lft) -1
        return 1 + countNodes(root->left)+countNodes(root->right);
    }
    int  leftHeight(TreeNode* node){
        int h = 0;
        while(node){
            h++;
            node = node->left;
        }
        return h;
    }
    int  rightHeight(TreeNode* node){
        int h = 0;
        while(node){
            h++;
            node = node->right;
        }
        return h;
    }

};

// TC = O(log(n)^2) |  SC = O(h) -> where n = nodes, h = height of tree.

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(9);
    Solution sl;
    int cn = sl.countNodes(root);
    cout<<"Total nodes in the binary tree are: "<<cn<<endl;
    return 0;
}