#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution101 {
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
    bool dfs(TreeNode* l, TreeNode* r) {
        if (!l && !r) { // both
            return true;
        }
        if (!l || !r) { // one of l or r is null
            return false;
        }
        return l->val == r->val && dfs(l->left, r->right) && dfs(l->right, r->left);
    }
    // 递归
    bool isSymmetric(TreeNode* root) {
        //root == null, left or right == null
        return dfs(root, root);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution101

using namespace solution101;
int main() {
    std::cout << "Leetcode " << 101 << std::endl;
    Solution solution = Solution();

    return 0;
}