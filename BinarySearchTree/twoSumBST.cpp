/* Two sum in BST
Given the root of a binary search tree and an integer k.Return true if there exist two elements in the BST such that their sum is equal to k otherwise false.
Examples:
Input : root = [5, 3, 6, 2, 4, null, 7] , k = 9
Output : true
Explanation : The BST contains multiple pair of nodes that sum up to k.
3 + 6 => 9.
5 + 4 => 9.
2 + 7 => 9.
Input : root = [5, 3, 6, 2, 4, null, 7] , k = 14
Output : false
Explanation : There is no pair in given BST that sum up to k.
*/
/*Approach:
By using the two pointer method on the BST with the help of BSTIterator,
BSTIterator helps to finding the next element (before/after).
                    5
                  /   \
                 3     6
                / \     \
left pointer = 2   4     7 = right pointer
if(l+r<) move left;
else move right;
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

// TC = O(H) | SC = O(1) : Where H is the height of the tree.
class BSTIterator{
private:
    stack<TreeNode*> st;
    bool reverse = true; // For checking the left or right part of the tree.
    void pushAll(TreeNode* node, bool isReverse){
        reverse = isReverse;
        if(isReverse)
            for( ; node!=nullptr; st.push(node), node = node->right);
        else
            for( ; node!=nullptr; st.push(node), node = node->left);
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        pushAll(root, isReverse);
    }
    
    int next() {
        TreeNode* tempNode = st.top();
        st.pop();
        if(reverse)
            pushAll(tempNode->left, reverse);
        else
            pushAll(tempNode->right, reverse);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution{
public:
    bool twoSumBST(TreeNode* root, int k){
        BSTIterator lft(root, false); // For finding next element
        BSTIterator rgt(root, true); // For finding before element
        int i = lft.next();
        int j = rgt.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j < k)
                i = lft.next();
            else
                j = rgt.next();
        }
        return false;
    }
};

int main(){
    // 5, 3, 6, 2, 4, null, 7] , k = 9
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sl;
    cout<<sl.twoSumBST(root, 9)<<endl;

    return 0;
}