// Kth largest/smallest element in Binary Search Tree

#include <iostream>
#include<vector>
#include <climits>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    int k = 3;
    void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest){
        if (!node || counter >= k) return;
        reverseInorder(node->right, counter, k, kLargest);
        counter++;
        if (counter == k) {
            kLargest = node->val;
            return;
        }
        reverseInorder(node->left, counter, k, kLargest);
    }
    void inorder(TreeNode* node, int& counter, int k, int& kSmallest){
        if (!node || counter >= k) return;
        inorder(node->left, counter, k, kSmallest);
        counter++;
        if (counter == k) {
            kSmallest = node->val;
            return;
        }
        inorder(node->right, counter, k, kSmallest);
    }
    // TC = O(N)
    pair<int, int> findKth(TreeNode* root, int k){
        int kSmallest = INT_MIN, kLargest = INT_MIN;
        int counter = 0;
        inorder(root, counter, k, kSmallest);
        counter = 0;
        reverseInorder(root, counter, k, kLargest);
        return make_pair(kSmallest, kLargest);

    }
    // display tree node using preorder traversal. TC = O(N): where N is No. of node in the tree.
    void preorder(TreeNode* root){
        if(!root) return;
        preorder(root->left);
        cout<<root->val<<" ";
        preorder(root->right);
    }
};
int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    Solution sl;
    sl.preorder(root);
    int k = 3;
    pair<int, int> ans = sl.findKth(root, k);
    cout<<endl<<k<<"'th Smallest is: "<<ans.first<<" and Largest is: "<<ans.second<<endl;
    return 0;
}