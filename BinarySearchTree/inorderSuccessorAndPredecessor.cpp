// Inorder successor and predecessor in BST

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class Solution{
public:
    int indorderSuccessor(TreeNode* root, TreeNode* key){
        int successor = -1;
        while (root!=nullptr){
            if(key->val >= root->val){
                root = root->right;
            } else{
                successor = root->val;
                root = root->left;
            }
        }
        return successor;
    }

    int inorderPredecessor(TreeNode* root, TreeNode* key){
        int predecessor = -1;
        while (root!=nullptr){
            if(key->val <= root->val){
                root = root->left;
            } else{
                predecessor = root->val;
                root = root->right;
            }
        }
        return predecessor;
    }
    


    pair<int, int> result(TreeNode* root, TreeNode* key){
        pair<int, int> ans;
        ans.first = inorderPredecessor(root, key);
        ans.second = indorderSuccessor(root, key);
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(12);

    Solution sl;
    pair<int, int> ans = sl.result(root, root->left->left);

    cout<<ans.first<<" "<<ans.second<<endl;
    
}