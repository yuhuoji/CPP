/**
 * @date 2023-06-06
 * 102. Binary Tree Level Order Traversal
 */
#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) { // root == nullptr
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();             // 当前层的节点个数
            res.push_back(vector<int>());                // 添加新的一层
            for (int i = 0; i < currentLevelSize; i++) { // 遍历当前层的所有节点
                auto node = q.front();
                q.pop();
                res.back().push_back(node->val); // 将当前层的节点值加入到res的最后一层
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
};

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    //    1
    //  2   3
    // 4 5

    Solution s;
    vector<vector<int>> res = s.levelOrder(root);
    // 输出res
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res.at(i).size(); j++) {
            cout << res.at(i).at(j) << " ";
        }
        cout << endl;
    }
}