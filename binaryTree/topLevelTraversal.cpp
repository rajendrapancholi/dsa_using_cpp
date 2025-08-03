#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr){};
};

class TreeNode{
    public:
    Node* root;
    TreeNode(): root(nullptr){};
    vector<pair<int, int>> topLevelTraversal(Node* root){
        vector<pair<int, int>> res;
        if(root == nullptr) return res;
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto qel = q.front();
            q.pop();
            Node* node = qel.first;
            int lvl = qel.second;
            if(mpp.find(lvl)==mpp.end())
                mpp[lvl]=node->val;
            if(node->left)
                q.push({node->left, lvl-1});
            if(node->right)
                q.push({node->right, lvl+1});
        }
        for(auto x: mpp){
            res.push_back(x);
        }
        return res;
    }
    
};

int main()
{
    TreeNode tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(10);
    tree.root->left->left->right = new Node(5);
    tree.root->left->left->right->right = new Node(6);
    tree.root->right = new Node(3);
    tree.root->right->right = new Node(10);
    tree.root->right->left = new Node(9);
    // TC = O(n); SC = O(n)
    vector<pair<int,int>> ans = tree.topLevelTraversal(tree.root);
    for(auto x: ans){
        cout<<x.second<<endl;
    }


    return 0;
}
