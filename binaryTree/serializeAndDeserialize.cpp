// Serialize And Deserialize a Binary Tree
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            if (curNode == nullptr) {
                s += "#,";
            } else {
                s += to_string(curNode->val) + ",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream s(data); // This line creates a `stringstream` object named `s` and initializes it with the contents of the string `data`. The `data` variable should contain a string that you want to process.
        string str;
        getline(s, str, ','); // This function call reads from the `stringstream` `s` and extracts characters into the string str until it encounters the specified delimiter, which in this case is a comma (,). The getline function will read characters from the stream and store them in str until it finds the comma, at which point it stops reading. The comma itself is not included in the resulting string.
        TreeNode* root = new TreeNode(stoi(str)); // convert str to integer
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
void inorder(TreeNode* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = solution.deserialize(serialized);
    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}
                            