/**********************
Program Name        : Balance binary tree.
Author              : Rajendra Pancholi
Date of creation    : 28/07/2025
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr){};
};

class TreeNode{
    public:
    Node* root;
    TreeNode():root(nullptr){};
    bool isBalance(Node* root){
        return dfsHeight(root) !=-1;
    }
    int dfsHeight(Node* root){
        if (root==nullptr) return 0;
        int leftHeight = dfsHeight(root->left);
        // if(leftHeight==-1) return -1;
        int rightHeight = dfsHeight(root->right);
        // if(rightHeight==-1) return -1;
        if (abs(leftHeight-rightHeight)>1) return -1;
        return max(leftHeight, rightHeight)+1;
    }
};

int main(){
    TreeNode tree;
    tree.root = new Node(1);
    tree.root->left = new Node(3);   
    tree.root->right = new Node(2);
    tree.root->left->left = new Node(5);   
    tree.root->left->right = new Node(4);   
    tree.root->left->left->left = new Node(7);   
    tree.root->left->left->right = new Node(8);   

    
    bool bt = tree.isBalance(tree.root);
    cout<<bt<<endl;
    return 0;
}