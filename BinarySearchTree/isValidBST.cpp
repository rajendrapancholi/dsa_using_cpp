// Check given binary search tree is valid or not.

#include<iostream>
#include<climits>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    bool isValidBST(TreeNode* root){ 
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode* root, long minVal, long maxVal){
        if(!root) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
    }

};
using namespace std;

int main(){
    Solution sl;
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    
    TreeNode* root3 = new TreeNode(3);
    root3->left = new TreeNode(2);
    root3->left->left = new TreeNode(1);
    root3->right = new TreeNode(4);

    cout<<sl.isValidBST(root1)<<endl;
    cout<<sl.isValidBST(root2)<<endl;
    cout<<sl.isValidBST(root3)<<endl;
    
    return 0;
}
