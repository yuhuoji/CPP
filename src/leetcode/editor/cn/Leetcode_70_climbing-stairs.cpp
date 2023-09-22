#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution70 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) {
            return n;
        }
        int a =1,b=2,sum;
        for (int i = 3; i <= n; ++i) {
            sum = a+b;
            a=b;
            b=sum;
        }
        return sum;
    }
    int climbStairs2(int n) {
        if (n<=2) {
            return n;
        }
        int dp[n+1] ;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    // Time Limit Exceeded
    // recursion, use one dimension space, fn = fn-1 + fn-2
    int climbStairs1(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs1(n - 1) + climbStairs1(n - 2);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution70

using namespace solution70;
int main() {
    std::cout << "Leetcode "
              << "70" << std::endl;
    Solution solution = Solution();
        int n = 5;
        cout << solution.climbStairs1(n) << endl;
        cout << solution.climbStairs1(n) << endl;
    return 0;
}