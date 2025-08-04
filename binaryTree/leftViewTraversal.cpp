#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
    vector<pair<int, int>> leftViewTravesal(Node* root){
        vector<pair<int, int>> res;
        if(!root) return res;
        queue<pair<Node*, int>> q;
        map<int, int> mapp;
        q.push({root, 0});
        while(!q.empty()){
            auto qel = q.front();
            q.pop();
            Node* node = qel.first;
            int lvl = qel.second;

            if(mapp.find(lvl)==mapp.end())
                mapp[lvl] = node->val;
            if(node->left) // go to left and update its level
                q.push({node->left, lvl+1});
            if(node->right) // go to right and update its level
                q.push({node->right, lvl+1});
            
        }
        for(auto x: mapp){
            res.push_back(x);
        }
        return res;
    }

    vector<pair<int, int>> rightViewTravesal(Node* root){
            vector<pair<int, int>> res;
            if(!root) return res;
            queue<pair<Node*, int>> q;
            map<int, int> mapp;
            q.push({root, 0});
            while(!q.empty()){
                auto qel = q.front();
                q.pop();
                Node* node = qel.first;
                int lvl = qel.second;

                mapp[lvl] = node->val;
                if(node->left) // go to left and update its level
                    q.push({node->left, lvl+1});
                if(node->right) // go to right and update its level
                    q.push({node->right, lvl+1});
                
            }
            for(auto x: mapp){
                res.push_back(x);
            }
            return res;
        }
};


int main(){
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
    vector<pair<int,int>> leftAns= tree.leftViewTravesal(tree.root);
    vector<pair<int,int>> rightAns= tree.rightViewTravesal(tree.root);
    cout<<"Left View of binary tree"<<endl;
    for(auto x: leftAns){
        cout<<x.second<<" ";
    }
    cout<<"\nRight View of binary tree"<<endl;
    for(auto x: rightAns){
        cout<<x.second<<" ";
    }
    return 0;
}