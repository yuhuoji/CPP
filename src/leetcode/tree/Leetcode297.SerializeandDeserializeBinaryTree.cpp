/**
 *
 * 297. Serialize and Deserialize Binary Tree
 */

// Definition for a binary tree node.
#include <iostream>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};
class Codec {
private:
    string serialize_dfs(TreeNode* root, string str) {
        if (root == nullptr) {
            str.append("null,");
        } else {
            str.append(to_string(root->val) + ",");
            str = serialize_dfs(root->left, str);
            str = serialize_dfs(root->right, str);
        }
        return str; 
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serialize_dfs(root, "");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3); 
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Codec ser, deser;
    //显示树的结构
    //   1
    // 2   3
    //    4 5
    string str = ser.serialize(root);
    cout << str << endl;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));
    // cout << ans->val << endl;
    // cout << ans->left->val << endl;
    // cout << ans->right->val << endl;
    // cout << ans->right->left->val << endl;
    // cout << ans->right->right->val << endl;
    return 0;
}
