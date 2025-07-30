/**********************
Program Name        : Zig Zag Traversal Of Binary Tree
Author              : Rajendra Pancholi
Date of creation    : 29/07/2025
Organization        : NIT Patna
***********************/

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> zigZagLevelOrder(Node* root){
        vector<vector<int>> result;
        if(root==nullptr) return result;
        queue<Node*> queueNodes;
        queueNodes.push(root);
        bool l2r = true;
        while (!queueNodes.empty())
        {
            int sz = queueNodes.size();
            vector<int> row(sz);
            for (int i = 0; i < sz; i++)
            {
                Node* node = queueNodes.front();
                queueNodes.pop();
                int idx = (l2r)? i: sz-i-1;
                row[idx] = node->data;
                if(node->left) queueNodes.push(node->left);
                if(node->right) queueNodes.push(node->right);
            }
            l2r = !l2r;
            result.push_back(row);
        }
        
        return result;
    }

    
};
int main(){
    TreeNode tree1;
    tree1.root = new Node(1);
    tree1.root->left = new Node(2);
    tree1.root->left->left = new Node(4);
    tree1.root->left->right = new Node(5);
    tree1.root->right = new Node(3);
    tree1.root->right->right = new Node(6);
    vector<vector<int>> ans = tree1.zigZagLevelOrder(tree1.root);
    for (auto x: ans){
        for (auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}