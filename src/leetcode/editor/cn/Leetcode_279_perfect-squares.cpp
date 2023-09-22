#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution279 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动态规划
    // f(n) = 1 + min{f(n-j^2)}, j in [1, n^(1/2)]
    int numSquares(int n) {
        int dp[n + 1]; // dp[0...n]
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) { // dp[i], i in 1...n
            int count = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                count = min(count, 1 + dp[i - j * j]);
            }
            dp[i] = count;
        }
        return dp[n];
    }
    // 递归
    int numSquares1(int n) {
        if (n == 0) {
            return 0;
        }
        int count = INT_MAX;
        for (int i = 1; i * i <= n; ++i) {
            count = min(count, 1 + numSquares(n - i * i));
        }
        return count;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution279

using namespace solution279;
int main() {
    std::cout << "Leetcode "
              << "279" << std::endl;
    Solution solution = Solution();
    int n = 16;
    cout << solution.numSquares1(n) << endl;
    cout << solution.numSquares(n) << endl;

    return 0;
}