/**********************
Program Name        : Maximum Sum Path in Binary Tree
Author              : Rajendra Pancholi
Date of creation    : 29/07/2025
Organization        : NIT Patna
***********************/

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr){};
};


class TreeNode{
    public:
    Node* root;
    TreeNode(): root(nullptr){};
    int maxPath(Node* root, int& maxi){
        if(root==nullptr) return 0;
        int leftSum = max(0, maxPath(root->left, maxi));
        int rightSum = max(0,maxPath(root->right, maxi));
        maxi = max(maxi, (leftSum+rightSum+root->data));
        return (root->data)+ max(leftSum, rightSum);
    }
};


int main(){
    TreeNode tree;
    tree.root = new Node(2);
    tree.root->left = new Node(-1);   
    // tree.root->right = new Node(20);
    // tree.root->right->left = new Node(15);   
    // tree.root->right->right = new Node(7);
    int maxi =0;
    int ans = tree.maxPath(tree.root, maxi);
    cout<<maxi<<endl;
    cout<<ans<<endl;
    return 0;
}