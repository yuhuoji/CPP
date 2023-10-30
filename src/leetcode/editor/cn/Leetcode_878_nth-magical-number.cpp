#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution878 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 二分查找
    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1;
        long long r = 1ll * n * min(a, b);

        // 求有几个a、b的因数
        auto check = [&](int m) {
            long long lcm_ab = std::lcm(a, b);
            int cnt = m / a + m / b - m / lcm_ab;
            return cnt;
        };

        while (l <= r) {
            long long m = ((r - l) >> 1) + l;
            int cnt = check(m);
            if (cnt >= n) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l % MOD;
    }

    static constexpr int MOD = 1'000'000'007;
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution878

using namespace solution878;
int main() {
    std::cout << "Leetcode "
              << "878" << std::endl;
    Solution solution;
    //    1000000000
    //        40000
    //        40000
    // 999720007
    //std::lcm(a, b)
    return 0;
}