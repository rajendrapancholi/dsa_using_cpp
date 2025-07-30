/**********************
Program Name        : Check if two trees are identical
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
    bool isIdentical(Node* root1, Node* root2){
        if(root1==nullptr || root2 ==nullptr) return root1==root2;
        return ((root1->data==root2->data) && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
    }
    
};
int main(){
    TreeNode tree1;
    tree1.root = new Node(1);
    tree1.root->left = new Node(2);
    tree1.root->right = new Node(4);
    tree1.root->right->left = new Node(5);
    tree1.root->right->right = new Node(6);
    TreeNode tree2;
    tree2.root = new Node(1);
    tree2.root->left = new Node(2);
    tree2.root->right = new Node(4);
    tree2.root->right->left = new Node(5);
    tree2.root->right->right = new Node(6);
    bool ans = tree1.isIdentical(tree1.root, tree2.root);
    cout<<ans<<endl;
    return 0;
}