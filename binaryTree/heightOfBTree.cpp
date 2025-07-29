/**********************
Program Name        : Find the height of the binary tree.
Author              : Rajendra Pancholi
Date of creation    : 28/07/2025
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
    // TC = O(n)
    int check(Node* root){
        if(root == nullptr) return 0;
        int lh = check(root->left);
        int rh = check(root->right);
        return max(lh, rh) + 1;
    }
};


int main(){
    TreeNode tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);   
    tree.root->right = new Node(3);   
    tree.root->right->left = new Node(4);   
    tree.root->right->right = new Node(5);
    tree.root->right->right->left = new Node(7);
    tree.root->right->right->right = new Node(8);
    int height = tree.check(tree.root);
    cout<<height<<endl;
    return 0;
}