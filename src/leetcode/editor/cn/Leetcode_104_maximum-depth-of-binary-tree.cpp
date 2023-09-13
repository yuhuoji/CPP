#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution104 {
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qsize = q.size();
            while ((qsize--) > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution104

using namespace solution104;
int main() {
    std::cout << "Leetcode " << 104 << std::endl;
    Solution solution = Solution();

    return 0;
}