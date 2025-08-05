
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int mmin = q.front().second;
            
            int first, last;

            for (int i = 0; i < size; i++) {
                int cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) {
                    first = cur_id;
                }

                if (i == size - 1) {
                    last = cur_id;
                }

                if (node->left) {
                    q.push({node->left, cur_id * 2 + 1});
                }

                if (node->right) {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }

    int widthOfBinaryTree2(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        long long res = 1;
        queue<pair<TreeNode*, long long>> q;
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            long long cnt = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            
            res = max(res,end-start + 1);
            
            for(int i = 0; i <cnt; ++i)
            {
                pair<TreeNode*, int> p = q.front();
                long long idx = p.second - start;
                
                q.pop();
                
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});
                
                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        
        return res;
    }


};


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: "
                        << maxWidth << endl;

    return 0;
}
                            