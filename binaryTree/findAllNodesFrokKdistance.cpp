// All Nodes Distance K in Binary Tree

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode* ,TreeNode*> parent;
    void inorder(TreeNode* root){
        // if(root==NULL) return;
        if(!root) return;
        if(root->left!=NULL)
            parent[root->left]=root;
        inorder(root->left);
        if(root->right!=NULL)
            parent[root->right]=root;
        inorder(root->right);
    }
    void BFS(TreeNode* target,int k,vector<int>& result){
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);

        while(!q.empty()){
            int n=q.size();
            if(k==0){
                break;
            }
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL && !visited.count(curr->left->val)){
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right!=NULL && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                // parent.count(curr) it finds key present or not in a parent
                if(parent.count(curr) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }

            }
            k--;
        }
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            result.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        inorder(root);
        BFS(target,k,result);
        return result;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution sol;
    int k = 2;
    vector<int> ans = sol.distanceK(root, root->left, k);
    for ( auto x: ans){
        cout<<x<<" ";
    }

    return 0;
}