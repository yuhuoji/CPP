#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2003 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // REVIEW @date 2023-10-31 不会

    // dfs, 从下向上遍历, 从1开始尝试基因值
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        auto it = find(nums.begin(), nums.end(), 1);
        if (it == nums.end()) { // 不存在基因值为1
            return ans;
        }

        // 建树, 邻接链表
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; ++i) {
            tree[parents[i]].push_back(i);
        }

        unordered_set<int> visited; // 记录出现过的基因值
        // 深度优先遍历x子树，记录所有出现过的基因值
        function<void(int)> dfs = [&](int x) {
            visited.insert(nums[x]);
            for (int son : tree[x]) {
                if (!visited.count(nums[son])) {
                    dfs(son);
                }
            }
        };

        int mex = 2; // 存在1，当前2是可能的最小的
        int cur = it - nums.begin();
        while (cur >= 0) { // 从底向上遍历节点，到根节点 parent[0] = -1 退出
            dfs(cur);
            while (visited.count(mex)) { // 包含此基因值，找到最小的没被包含的基因值
                mex++;
            }
            ans[cur] = mex;     // 记录缺失的基因值
            cur = parents[cur]; // 自底向上遍历
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2003

using namespace solution2003;
int main() {
    std::cout << "Leetcode "
              << "2003" << std::endl;
    Solution solution;

    vector<int> parents = {-1, 0, 0, 2};
    vector<int> nums = {1, 2, 3, 4};
    auto ans = solution.smallestMissingValueSubtree(parents, nums);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}