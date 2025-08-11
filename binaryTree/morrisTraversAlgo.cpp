#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> getPreorder(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        while (cur != NULL) { 
            if (cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = cur;
                    inorder.push_back(cur->val);
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
    vector<int> getInorder(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        while (cur != NULL) { 
            if (cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};

// TC = O(n) | SC = O(1)
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    Solution sol;
    vector<int> preorder = sol.getPreorder(root);
    cout << "Binary Tree Morris Preorder Traveral: ";
    for(int i = 0; i< preorder.size(); i++){
        cout << preorder[i] << " ";
    }
    cout << endl;
    vector<int> inorder = sol.getInorder(root);
    cout << "Binary Tree Morris Inorder Traveral: ";
    for(int i = 0; i< inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;
    return 0;
}
                            