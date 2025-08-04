#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==nullptr || helper(root->left, root->right);
    }
    bool helper(TreeNode* left, TreeNode* right){
        if(left==nullptr || right==nullptr) return left==right;
        
        return (left->val==right->val) && helper(left->left, right->right) && helper(left->right, right->left);
    }
};

int main(){
    Solution tree;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool ans = tree.isSymmetric(root);
    cout<<ans<<endl;
    return 0;
}