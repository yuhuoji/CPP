#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution300 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // REVIEW @date 2023-11-02 难 最长递增子序列

    //  贪心 + 二分查找
    int lengthOfLIS(vector<int>& nums) {
        vector<int> g;
        for (auto num : nums) {
            auto it = lower_bound(g.begin(), g.end(), num);
            if (it == g.end()) {
                g.push_back(num);
            } else {
                *it = num;
            }
        }
        return g.size();
    }

    // dp
    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i]++;
        }
        return *max_element(dp, dp + n);
    }

    // 记忆化搜索
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        int memo[n];
        memset(memo, 0, sizeof(memo));
        function<int(int)> dfs = [&](int i) {
            int res = 0;
            for (int j = 0; j < i; ++j) { // 枚举之前的，已经计算过memo
                if (nums[j] < nums[i]) {
                    res = max(res, dfs(j));
                }
            }
            memo[i] = res + 1;
            return memo[i];
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }

    // 枚举+dfs，TLE
    // 时间O(N^2) 空间O(N)
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();

        // 枚举选哪个
        // nums[i]作为最后一个元素
        function<int(int)> dfs = [&](int i) {
            int res = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) { // 严格递增
                    res = max(res, dfs(j));
                }
            }
            return res + 1;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) { // 枚举以每个位置结尾的最长子序列
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution300

using namespace solution300;
int main() {
    std::cout << "Leetcode "
              << "300" << std::endl;
    Solution solution;

    return 0;
}