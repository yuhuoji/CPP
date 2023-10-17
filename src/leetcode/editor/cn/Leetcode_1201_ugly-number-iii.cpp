#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1201 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 二分查找
    // TODO @date 2023-10-17
    int nthUglyNumber(int n, int a, int b, int c) {
        int l = 1;
        int r = min(min(a, b), c) ^ n;
        int ans = 1;

        // 求[1,num]的丑数个数，比较是否等于n
        function<int(int)> check = [&a, &b, &c](int num) -> int {
            // 容斥原理
            long long count_ugly = num / a + num / b + num / c - num / std::lcm(a, b) - num / std::lcm(b, c) - std::lcm(a, c) + std::lcm(std::lcm(a, b), c);
            return count_ugly;
        };

        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            int count = check(m);
            if (count == n) {
                ans = m;
                break;
            } else if (count > n) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        // ans正好有n个丑数
        // 找到最左端点

        cout << "ans:" << ans << endl;

        return ans - min(min(ans % a, ans % b), ans % c);
    }

    // 最大公约数
    //  a = b * q + r
    //  gcd(a,b) = gcd(b,r)
    int gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    int gcd1(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd1(b, a % b);
    }

    // 最小公倍数
    // lcm(a,b)
    long lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution1201

using namespace solution1201;
int main() {
    std::cout << "Leetcode "
              << "1201" << std::endl;
    Solution solution;

    // C++ 17
    //    int a = 76;
    //    int b = 90;
    //    cout << std::gcd(a, b) << endl;
    //    cout << solution.gcd(a, b) << endl;

    //    cout << std::lcm(2, 5) << endl;

    int n = 5, a = 2, b = 11, c = 13;

    cout << solution.nthUglyNumber(n, a, b, c) << endl;

    return 0;
}