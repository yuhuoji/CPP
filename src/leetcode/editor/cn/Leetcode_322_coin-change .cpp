#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution322 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //完全背包
    //动态规划
public:
    // 动态规划
    //    f(i) = 1 + min{f(i - coin[j])}
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1); // 默认都拼不出
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) { // i from 1 to amount
            for (int coin : coins) {
                // dp[i] = 1 + 合理的dp[i - coin]
                if (coin > i) { // 合理的coin才尝试，防止dp数组越界
                    continue;
                }
                int count = dp[i - coin];
                if (count != -1 && dp[i] == -1) {
                    dp[i] = 1 + count;
                } else if (count != -1 && dp[i] != -1) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[amount];
    }

    // 记忆化搜索?递归
    vector<int> count;
    int coinChange2(vector<int>& coins, int amount) {
        count.resize(amount); // coin[i] >= 1, amount from 1 to amount
        return dp(coins, amount);
    }

    int dp(const vector<int>& coins, int remain) {
        if (remain < 0) {
            return -1;
        }
        if (remain == 0) {
            return 0;
        }
        int ans = INT_MAX;
        for (auto coin : coins) {
            int res = dp(coins, remain - coin);
            if (res >= 0 && res < ans) {
                ans = res + 1;
            }
        }
        count[remain - 1] = ans == INT_MAX ? -1 : ans;
        return count[remain - 1];
    }

    // 递归 超时
    // f(i) = 1 + min{f(i - coin[j])}
    int coinChange1(vector<int>& coins, int amount) {
        return process1(coins, amount);
    }
    int process1(const vector<int>& coins, int amount) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        int count = INT_MAX;
        for (auto coin : coins) { // 尝试当前硬币
            int res = process1(coins, amount - coin);
            if (res >= 0 && res < count) {
                count = res + 1;
            }
        }
        if (count == INT_MAX) { // 无有效结果
            return -1;
        } else {
            return count;
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution322

using namespace solution322;
int main() {
    std::cout << "Leetcode "
              << "322" << std::endl;
    Solution solution = Solution();
    vector<int> coins = {2};
    int amount = 3;
    cout << solution.coinChange(coins, amount);
    return 0;
}