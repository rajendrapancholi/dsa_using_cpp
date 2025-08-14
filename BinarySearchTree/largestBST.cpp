// Largest BST in binary Tree.
#include<iostream>
#include<climits>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    TreeNode* largestBST(TreeNode* root){
        if(!root) return nullptr;
        if(root->right) return largestBST(root->right);
        return root;
    }
};
using namespace std;

int main(){
    Solution sl;
    TreeNode* root1 = new TreeNode(6);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(4);
    root1->left->right->left = new TreeNode(3);
    root1->left->right->right = new TreeNode(5);
    root1->right = new TreeNode(8);
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(9);


    cout<<sl.largestBST(root1)->val<<endl;

    
    return 0;
}
