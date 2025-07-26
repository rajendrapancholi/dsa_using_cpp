/**********************
Program Name        : Inorder Traversal of a Binary Tree
Author              : Rajendra Pancholi
Date of creation    : 25/07/2025
Organization        : NIT Patna
***********************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void iterativeTraversal(Node* root){
        vector<int> ans;
        if (root == nullptr)
            return;

        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* nd = st.top();
            st.pop();
            if(nd->left!=nullptr){
                st.push(nd->left);
            }
            if(nd->right!=nullptr){
                st.push(nd->right);
            }
            
            ans.push_back(nd->data);
        }
        for(auto x: ans)
            cout<<x<<" ";
    }

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorderTraversal(root);
    cout << endl;
    iterativeTraversal(root); // TC=O(n) preorder travesal using iterative method 
    cout << endl;
    return 0;
}