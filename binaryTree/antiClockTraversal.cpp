/**********************
Program Name        : Boundary Traversal of a Binary Tree
Author              : Rajendra Pancholi
Date of creation    : 30/07/2025
Organization        : NIT Patna
***********************/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

class TreeNode
{
public:
    Node *root;
    TreeNode() : root(nullptr) {};

    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }
    void addLeftBoundary(Node* root, vector<int>& ans)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                ans.push_back(curr->val);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void addLeafNodes(Node *root, vector<int>& ans)
    {
        if (isLeaf(root))
        {
            ans.push_back(root->val);
            return;
        }
        if (root->left)
            addLeafNodes(root->left, ans);
        if (root->right)
            addLeafNodes(root->right, ans);
    }

    void addRightBoundary(Node *root, vector<int> &ans)
    {
        Node *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->val);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; --i)
        {
            ans.push_back(temp[i]);
        }
    }
    vector<int> boundryTravers(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        if(!isLeaf(root))
            ans.push_back(root->val);

        addLeftBoundary(root, ans);
        addLeafNodes(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};

int main()
{
    TreeNode tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->left->left = new Node(3);
    tree.root->left->left->right = new Node(4);
    tree.root->left->left->right->left = new Node(5);
    tree.root->left->left->right->right = new Node(6);
    tree.root->right = new Node(7);
    tree.root->right->right = new Node(8);
    tree.root->right->right->left = new Node(9);
    tree.root->right->right->left->left = new Node(10);
    tree.root->right->right->left->right = new Node(11);
    vector<int> ans;
    ans = tree.boundryTravers(tree.root);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}