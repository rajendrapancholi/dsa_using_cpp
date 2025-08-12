// Ceil in a Binary Search Tree

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
    int findCeil(TreeNode* root, int key){
        int ceil = -1; 
        while(root){
            if(root->val == key){
                ceil = root->val;
                return ceil;
            } 
            if(key > root->val){
                root = root->right;
            }
            else{ 
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }
};
int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    Solution sl;
    int key = 8;
    int ans  = sl.findCeil(root, key);
    cout<<ans<<endl;
    return 0;
}