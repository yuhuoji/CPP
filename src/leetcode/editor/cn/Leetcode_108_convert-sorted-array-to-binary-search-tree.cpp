#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution108 {
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
    // 中序遍历
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = (int) nums.size();
        return inorderBuildTree(nums, 0, n - 1);
    }
    TreeNode* inorderBuildTree(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

//        int m = ((right - left) >> 1) + left;              // m<=中间数
//        int m = ((right - left + 1) >> 1) + left;          // m>=中间数
        int m = ((right - left + rand() % 2) >> 1) + left; // m随机

        auto root = new TreeNode(nums[m]);
        root->left = inorderBuildTree(nums, left, m - 1);
        root->right = inorderBuildTree(nums, m + 1, right);
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution108

using namespace solution108;
int main() {
    std::cout << "Leetcode "
              << "108" << std::endl;
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    cout << solution.sortedArrayToBST(nums) << endl;
    return 0;
}