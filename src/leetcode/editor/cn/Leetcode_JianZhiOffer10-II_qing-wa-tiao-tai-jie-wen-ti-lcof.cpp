#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution_Offer_10_II {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 3dp 用有限变量优化空间复杂度
    int numWays(int n) {
        if(n==0||n==1){
            return 1;
        }
        int a = 1, b = 1, sum = 0;
        for (int i = 2; i <= n; ++i) { // 2...n
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }

    // 2记忆化搜索
    int numWays2(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int dp[n + 1]; // 0,1,2,...,n

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }

        return dp[n];
    }
    // 1递归
    int numWays1(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return (numWays1(n - 1) + numWays1(n - 2)) % 1000000007;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution_Offer_10_II

using namespace solution_Offer_10_II;
int main() {
    std::cout << "Leetcode "
              << "Sword Offer 10- II" << std::endl;
    Solution solution = Solution();
    int n = 9;
    cout << "recursion :" << solution.numWays1(n) << endl;
    cout << "Memorized search :" << solution.numWays2(n) << endl;
    cout << "dp:" << solution.numWays(n) << endl;
    return 0;
}