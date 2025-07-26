/**********************
Program Name        : Postorder Traversal of a Binary Tree
Author              : Rajendra Pancholi
Date of creation    : 25/07/2025
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class TreeTraverse {
public:
    Node* root;

    TreeTraverse() {
        root = nullptr;
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
};

int main() {
    TreeTraverse tree;

    // Creating the following binary tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Postorder Traversal: ";
    tree.postorderTraversal(tree.root);
    cout << endl;

    return 0;
}
