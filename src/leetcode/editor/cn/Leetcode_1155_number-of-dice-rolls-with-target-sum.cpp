#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1155 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 二维动态规划
    // i个骰子和为j f(i,j) = \sum_\limits{x=1}^n f(i-1,j-x)
    // f(0,0) = 1
    // 不存在， f(i,j)=0 if j < 0
    int numRollsToTarget(int n, int k, int target) {
        // 0~n, 0~target+1
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        // 依赖关系
        // i=0行其他都为0
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                for (int x = 1; x <= k; ++x) {
                    if (j - x >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }
    static constexpr int MOD = 1000000007;
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution1155

using namespace solution1155;
int main() {
    std::cout << "Leetcode "
              << "1155" << std::endl;
    Solution solution;

    return 0;
}