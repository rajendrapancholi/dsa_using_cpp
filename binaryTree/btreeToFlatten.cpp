// Convert the Binary tree to flatten tree like linked list.


#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* prev = NULL;
    // TC = O(n) | SC = O(log2N) : H = N (skewed tree) -> space complexity is O(H) where H is the height of the Binary Tree.
    void flattenBruteForce(TreeNode* root) { 
       if(root==NULL){
           return;
       }
       flattenBruteForce(root->right);
       flattenBruteForce(root->left);
       root->right = prev;
       root->left = NULL;
       prev = root;
    }
    // TC = O(n) | SC = O(log2N) : H = N (skewed tree) -> space complexity is O(H) where H is the height of the Binary Tree.
    void flattenUsingStack(TreeNode* root) { 
       if(root==NULL){
           return;
       }
        stack<TreeNode*> st;
        st.push(root); 
        while (!st.empty()) {  
            TreeNode* cur = st.top(); 
            st.pop();  
            if (cur->right != NULL) {
                st.push(cur->right); 
            }
            if (cur->left != NULL) {
                st.push(cur->left); 
            }
            if (!st.empty()) {
                cur->right = st.top();
            }
            cur->left = NULL;  
        }
    }   
    /* 
    * usign morris algorithm to reduce the auxiliary(recursive stack space) space 
    * Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.
    * Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.
    */

    void flattenUsingMorris(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* pre = curr->left;
                while (pre->right) { // end of the right child of tree
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

void printPreorder(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printFlattenTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    sol.flattenBruteForce(root);
    cout << "Binary Tree After Flatten (Brute force):"<<endl;
    printFlattenTree(root);
    cout << endl;

    sol.flattenUsingStack(root);
    cout << "Binary Tree After Flatten (Stack):"<<endl;
    printFlattenTree(root);
    cout << endl;

    sol.flattenUsingStack(root);
    cout << "Binary Tree After Flatten (Morris):"<<endl;
    printFlattenTree(root);
    cout << endl;
    

    return 0;
}
                                