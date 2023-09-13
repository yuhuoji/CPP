#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution226 {
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // DFS
    TreeNode* invertTree1(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree1(root->left);
        invertTree1(root->right);
        return root;
    }
    // BFS
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* left = node->left;
            node->left = node ->right;
            node->right = left;
            if (node->left!= nullptr){
                q.push(node->left);
            }
            if (node->right){
                q.push(node->right);
            }
        }
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution226

using namespace solution226;
int main() {
    std::cout << "Leetcode " << 226 << std::endl;
    Solution solution = Solution();

    return 0;
}