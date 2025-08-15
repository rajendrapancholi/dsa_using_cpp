// Construct a BST from a preorder traversal
#include <iostream>
#include <vector>
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
    TreeNode* bstFromPreorder(vector<int>& arr){
        int i = 0;
        return build(arr, i, INT_MAX);
    }
    TreeNode* build(vector<int>& arr,int& i, int bound){
        if(i==arr.size() || arr[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(arr[i++]);
        root->left = build(arr, i, root->val);
        root->right = build(arr, i, bound);
        return root;
    }

    void indorder(TreeNode* node){
        if(!node) return;
        indorder(node->left);
        cout<<node->val<<" ";
        indorder(node->right);
    }
};


int main(){
    Solution sl;
    vector<int> arr = {8, 5, 1, 7, 10, 12};

    TreeNode* ans = sl.bstFromPreorder(arr);
    sl.indorder(ans);
    return 0;
}