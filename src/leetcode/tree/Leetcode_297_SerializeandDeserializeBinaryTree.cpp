/**
 * @date 2023-07-13
 * 297. Serialize and Deserialize Binary Tree
 * 用bfs序列化
 */
// Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
};
class Codec {
private:
    // preorder inorder postorder
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

    string serialize_bfs(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            /* code */
        }
        return "";
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        return serialize_dfs(root, "");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if ()
        {
            /* code */
        }
        
        return nullptr;
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
    // 显示树的结构
    //    1
    //  2   3
    //     4 5
    string str = ser.serialize(root);
    cout << str << endl;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));
    // cout << ans->val << endl;
    // cout << ans->left->val << endl;
    // cout << ans->right->val << endl;
    // cout << ans->right->left->val << endl;
    // cout << ans->right->right->val << endl;

    std::queue<TreeNode*> q;
    
    return 0;
}
