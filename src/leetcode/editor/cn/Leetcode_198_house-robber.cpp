#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution198 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 空间压缩
    int rob3(vector<int>& nums) {
        int n = nums.size(); // n>=1
        // i from 0 to n
        // 初始条件
        int p = 0;
        int q = nums[0];
        int money = q;
        // p, q, money
        // dp[i-2] dp[i-1] dp[i]
        for (int i = 2; i <= n; ++i) { // fill dp[i]
            money = max(q, p + nums[i - 1]);
            // 转移
            p = q;
            q = money;
        }
        return money; // 返回值
    }

    // 动态规划
    // 前i-1个房子 dp[i] = max{dp[i-1], dp[i-2] + nums[i-1]}
    int rob2(vector<int>& nums) {
        int n = nums.size(); // n>=1
        // i from 0 to n
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }

    // 递归
    // 子问题 f(k) 偷前k间房子的最大金额
    int rob(vector<int>& nums) {
        int n = nums.size();
        return f(nums, n);
    }

    // 偷前k个房子的钱 f(k) = max{f(k-1), nums[k-1] + f(k-2)}，k from 0 to n-1
    int f(const vector<int> nums, int k) {
        if (k == 0) {
            return 0;
        }
        if (k == 1) {
            return nums[0];
        }
        if (k == 2) {
            return max(nums[0], nums[1]);
        }

        return max(f(nums, k - 1), (nums[k - 1] + f(nums, k - 2)));
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution198

using namespace solution198;
int main() {
    std::cout << "Leetcode "
              << "198" << std::endl;
    Solution solution = Solution();
    //    [1,2,3,1]
    vector<int> nums = {1, 2, 3, 1};
    cout << solution.rob(nums) << endl;
    return 0;
}