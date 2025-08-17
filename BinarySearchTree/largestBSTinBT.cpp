// Largest BST in Binary Tree
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);
        
        // Get the value of right and left subtree of the current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise return [-inf, inf] so that parent can't be valid BST.
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(30);
    root->right->right->right = new TreeNode(40);
    root->right->right->right->right = new TreeNode(50);
    
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);

    Solution sl;
    cout << "Size of the largest BST in the binary tree: " << sl.largestBSTSubtree(root) << endl;
    cout << "Size of the largest BST in the binary tree: " << sl.largestBSTSubtree(root2) << endl;
    
    // Clean up memory (optional)
    delete root->right->right->right->right; // 50
    delete root->right->right->right; // 40
    delete root->right->right; // 30
    delete root->right; // 20
    delete root; // 10

    delete root2->right;
    delete root2->left;
    delete root2;
    return 0;
}
