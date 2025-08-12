// Search element in binary search tree (BST).

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};


// rule: [left<root<right]
class BinarySearchTree{
public:
    /*
    TC = best: O(1), Avg: O(log(N)), Worst: O(n) [skewed]
    SC = best: O(1), Avg: O(log(N)), Worst: O(n) [skewed]
    */ 
    bool findEle(TreeNode* root, int ele){
        if (!root) return false;
        if(root->val==ele) return true;
        else if(root->val < ele){
            return findEle(root->right, ele);
        }
        else {
            return findEle(root->left, ele);
        }
    }
    TreeNode* findEle1(TreeNode* root, int ele){
        while(root!=nullptr && root->val != ele){
            root = (root->val > ele)? root->left: root->right;
        }
        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->right  = new TreeNode(12);
    root->right->left  = new TreeNode(10);
    root->right->right  = new TreeNode(14);
    root->right->right->left  = new TreeNode(13);
    BinarySearchTree bts;
    int ele = 14;
    bool ans = bts.findEle(root, ele);
    cout<<ans<<endl;
    cout<<"using iteration."<<endl;    
    TreeNode* ans1 = bts.findEle1(root, ele);
    cout<<ans1->val<<endl;
    return 0;
}