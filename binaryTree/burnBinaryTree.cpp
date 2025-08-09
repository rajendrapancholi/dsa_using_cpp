#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T value; // Value of the node
    BinaryTreeNode* left; // Pointer to the left child
    BinaryTreeNode* right; // Pointer to the right child
    BinaryTreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
    // Destructor
    ~BinaryTreeNode() {
        // Optionally, you can add code here to delete child nodes if needed
        delete left;
        delete right;
    }
};


class Solultion{
    public:
    int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mpp, BinaryTreeNode<int>* target){
        queue<BinaryTreeNode<int>*> q;
        q.push(target);
        map<BinaryTreeNode<int>*, int> vis;
        vis[target]=1;
        int maxi=0;
        while(!q.empty()){
            bool fl = false;
            int sz = q.size();

            for (int i = 0; i < sz; i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){ //  Burn left child if it is exists.
                    fl = true;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){ // Burn right child if it is exists.
                    fl = true;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(mpp[node] && !vis[mpp[node]]){ // Burn the parent if it is exists.
                    fl = true;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
                
            }
            if(fl) maxi++; // when any burned node-> incremented by 1 for burning level
        }
         return maxi;
    }


    BinaryTreeNode<int>* bfsToMapPerent(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mpp, int& start){
        queue<BinaryTreeNode<int>*> q;
        BinaryTreeNode<int>* target;
        q.push(root);
        while (!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->value == start) target = node;
            if(node->left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        return target;
    }
    int timeToBurn(BinaryTreeNode<int>* root, int start){
        int maxi = 0;
        map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp;
        BinaryTreeNode<int>* target = bfsToMapPerent(root, mpp, start);
        maxi = findMaxDistance(mpp, target);
        return maxi;
    }

};
int main(){
    Solultion sl;
    BinaryTreeNode<int>* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->left->right->left = new BinaryTreeNode(6);
    root->left->right->right = new BinaryTreeNode(7);
    root->right = new BinaryTreeNode(3);
    int mxBurn = sl.timeToBurn(root, 2);
    cout<<mxBurn<<endl;
    return 0;
}