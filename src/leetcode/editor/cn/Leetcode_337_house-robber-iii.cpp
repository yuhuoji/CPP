#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution337 {
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
    // TODO @date 2023-10-15

    // 树型dp
    // 子问题rob(root,bool) 是否（可能）能偷root
    // ans = max{rob(root, true), rob(root, false)}
    // rob(root, true) = val + max{偷， 不偷}
    // rob(root, false) = 左树能偷 + 右树能偷
public:
    // 动态规划
    int rob3(TreeNode* root) {
        auto ans = dfs3(root);
        return max(ans[0], ans[1]);
    }

    // [select, not select]
    vector<int> dfs3(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto left = dfs3(root->left);
        auto right = dfs3(root->right);
        int a = root->val + left[1] + right[1];                  // 选root
        int b = max(left[0], left[1]) + max(right[0], right[1]); // 不选root
        return {a, b};
    }

    unordered_map<TreeNode*, int> f, g; // 空间 2n, select, not select
    int rob2(TreeNode* root) {
        dfs2(root);
        return max(f[root], g[root]);
    }

    // 后序遍历，先处理左右再处理root
    void dfs2(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs2(root->left);
        dfs2(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
    }

    // 递归 超时
    int rob1(TreeNode* root) {
        return max(robRecursive(root, true), robRecursive(root, false));
    }
    // select 是否可以选中root
    int robRecursive(TreeNode* root, bool select) {
        if (!root) {
            return 0;
        }
        if (select) { // 可以选root
            int case1 = root->val + robRecursive(root->left, false) + robRecursive(root->right, false);
            int case2 = robRecursive(root->left, true) + robRecursive(root->right, true);
            return max(case1, case2);
        } else { // 不选root
            return robRecursive(root->left, true) + robRecursive(root->right, true);
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution337

using namespace solution337;
int main() {
    std::cout << "Leetcode "
              << "337" << std::endl;
    Solution solution = Solution();
    string s1 = "[3,2,3,null,3,null,1]";
    TreeNode* root1 = stringToTreeNode(s1);
    cout << solution.rob(root1) << endl;

    string s2 = "[3,4,5,1,3,null,1]";
    TreeNode* root2 = stringToTreeNode(s2);
    //    cout << solution.rob(root2) << endl;

    return 0;
}