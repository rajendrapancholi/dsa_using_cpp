/**********************
Program Name        : Finding the diameter of a given tree.
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
    Node* right;;
        Node(int val): data(val), left(nullptr), right(nullptr){};
};
class TreeNode{
    public:
    Node* root;
    TreeNode(): root(nullptr){};
    int height(Node* root, int* d){
        if(root==nullptr) return 0;
        int leftHeight = height(root->left, d);
        int rightHeight = height(root->right, d);
        *d = max(*d, leftHeight + rightHeight);
        return 1+max(leftHeight, rightHeight);
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
    int d = 0;
    int diameter = tree.height(tree.root, &d);
    cout<<diameter<<endl;
    return 0;
}