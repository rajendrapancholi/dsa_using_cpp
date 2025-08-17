// Correct BST with two nodes swapped 

#include <iostream>
#include<climits>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int v) : val(v) , left(nullptr) , right(nullptr) {}
};
 

class Solution {
private:
     TreeNode *first;
     TreeNode* prev;
     TreeNode* middle;
     TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev!=nullptr && root->val < prev->val){
            // If this is first violation, mark these two nodes as `first` and `middle`
            if(first == nullptr){
                first = prev;
                middle = root;
            // If this is second violation, mark this node as last.
            } else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }

    void displayInorder(TreeNode* root){
        if(!root) return;
        displayInorder(root->left);
        cout<<root->val<<" ";
        displayInorder(root->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution sl;
    // sl.recoverTree(root);
    sl.displayInorder(root);


    return 0;
}