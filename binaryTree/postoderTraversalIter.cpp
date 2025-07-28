/**********************
Program Name        : Postorder traversal using 2 satcks
Author              : Rajendra Pancholi
Date of creation    : 26/07/2025
Organization        : NIT Patna
***********************/

#include <iostream>
#include <vector>
#include <stack>
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

    void postOrderTr(Node* root){
        stack<Node*> st1, st2;
        if (root==nullptr) return;
        st1.push(root);
        while (!st1.empty())
        {
            Node* nd = st1.top();
            st1.pop();
            st2.push(nd);
            if(nd->left!=nullptr){
                st1.push(nd->left);
            }
            if(nd->right!=nullptr){
                st1.push(nd->right);
            }
        
        }
        while(!st2.empty()){
            Node* d = st2.top();
            cout<<d->data<<" ";
            st2.pop();
        }
    }
};

int main(){
    TreeNode tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    cout << "Postorder Traversal: ";
    tree.postOrderTr(tree.root);
    cout << endl;
    return 0;
}