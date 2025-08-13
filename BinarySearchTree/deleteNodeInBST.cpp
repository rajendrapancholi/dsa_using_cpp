// Delete Node in a BST

#include <iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    TreeNode* delNode(TreeNode* root, int key){
        if(!root) return nullptr;
        if(root->val == key) return helper(root);

        TreeNode* node = root;
        while(root){
            if(root->val > key  ){ // if key is smaller (left subtree)
                if(root->left!=nullptr && root->left->val == key){
                    root->left = helper(root->left); // root=3
                    break;
                } else {
                    root = root->left;
                }
            }
            else{
                if(root->right!=nullptr && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return node;
    }

    TreeNode* helper(TreeNode* root){ // root = 3
        // if left is not exist or left is null then join the right to the root's left
        if(root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;
        TreeNode* lft = root->left;
        TreeNode* rgt = root->right;
        TreeNode* mlft = findLeft(rgt);
        mlft->left = root->left;
        return rgt;
    }
    TreeNode* findLeft(TreeNode* root){
        if(root->left == nullptr) return root;
        return findLeft(root->left);
    }

    // display tree node using preorder traversal. TC = O(N): where N is No. of node in the tree.
    void preorder(TreeNode* root){
        if(!root) return;
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};
int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution sl;
    int key = 3;
    cout<<"Before Deleting node "<<key<<"Tree is:"<<endl;
    sl.preorder(root);
    sl.delNode(root, key);
    cout<<"After Deleting node "<<key<<"Tree is:"<<endl;
    sl.preorder(root);
    return 0;
}