// import universal *.h
#include "../../../dependencies/include/bits/stdc++.h"

using namespace std;

// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
//
//
//
//  示例 1：
//
//
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]
//
//
//  示例 2：
//
//
// 输入：root = [1]
// 输出：[[1]]
//
//
//  示例 3：
//
//
// 输入：root = []
// 输出：[]
//
//
//
//
//  提示：
//
//
//  树中节点数目在范围 [0, 2000] 内
//  -1000 <= Node.val <= 1000
//
//
//  Related Topics 树 广度优先搜索 二叉树 👍 1773 👎 0

namespace solution102 {
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) { // root is a nullptr
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            res.push_back(vector<int>()); // 当前层
            for (int i = 0; i < currentLevelSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                res.back().push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return res;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution102

using namespace solution102;
int main() {
    std::cout << "leetcode 102" << std::endl;

    Solution solution = Solution();
    string treeNodeStr = "[3,9,20,null,null,15,7]";
    TreeNode* root = stringToTreeNode(treeNodeStr);

    vector<vector<int>> res = solution.levelOrder(root);

    for (const auto& innerVec : res) {
        for (int num : innerVec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}