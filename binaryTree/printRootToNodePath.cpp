/**********************
Program Name        : Print Root to Node Path in binary tree.
Author              : Rajendra Pancholi
Date of creation    : 26/07/2025
Organization        : NIT Patna
***********************/

#include <iostream>
#include <vector>
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

    vector<Node*> q;
    void helper(Node* root, int target){
        if(root==nullptr){
            return;
        }
        if(target == root->data){
            for (int i = 0; i < q.size(); i++)
            {
                cout<<q[i]->data<<" ";
            }
            cout<<target<<" ";
            
            return;
        }
        q.push_back(root);
        helper(root->left, target);
        helper(root->right, target);
        if(!q.empty())q.pop_back();
        
    }
};

int main(){
    TreeNode tree;
    tree.root = new Node(3);
    tree.root->left = new Node(5);
    tree.root->right = new Node(1);
    tree.root->left->left = new Node(6);
    tree.root->left->right = new Node(2);
    tree.root->right->left = new Node(0);
    tree.root->right->right = new Node(8);
    tree.root->left->right->left = new Node(7);
    tree.root->left->right->right = new Node(4);
    tree.helper(tree.root, 8);
    return 0;
}