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
    vector<vector<int>> verticalTraversal(Node* root){
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root,{0,0}});

        while (!q.empty())
        {
            auto qn = q.front();
            q.pop();
            Node* nd = qn.first;
            int ord = qn.second.first, lvl = qn.second.second;
            nodes[ord][lvl].insert(nd->val);
            if(nd->left){
                q.push({nd->left, {ord-1, lvl+1}});
            }
            if(nd->right){
                q.push({nd->right, {ord+1, lvl+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
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
    // TC = O(nlog(n)); SC = O(n)
    vector<vector<int>> ans = tree.verticalTraversal(tree.root);
    for(auto x: ans){
        for(auto y: x)
            cout<<y<<" ";
        cout<<endl;
    }

    return 0;
}
