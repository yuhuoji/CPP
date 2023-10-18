#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1201 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 二分查找
    // REVIEW @date 2023-10-18
    // TODO @date 2023-10-17
    // 用整数运算来避免浮点数精度问题
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = min(min(a, b), c);
        long long r = min(min(a, b), c) * n;

        // 求[1,num]的丑数个数，比较是否等于n
        function<long long(long long)> check = [=](long long num) {
            // 容斥原理
            long long lcm_ab = std::lcm(a, b);
            long long lcm_ac = std::lcm(a, c);
            long long lcm_bc = std::lcm(b, c);
            long long lcm_abc = std::lcm(std::lcm(a, b), c);
            return num / a + num / b + num / c - num / lcm_ab - num / lcm_ac - num / lcm_bc + num / lcm_abc;
        };

        while (l <= r) {
            long long m = ((r - l) >> 1) + l;
            long long count = check(m);
            if (count >= n) { // m说不定够
                r = m - 1;
            } else { // m肯定太小
                l = m + 1;
            }
        }
        // ans正好有n个丑数
        // 找到最左端点

        return l; // 有>=n个因数的第一个数
    }

    // 最大公约数
    // a = b * q + r
    // gcd(a,b) = gcd(b,r)
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
    long long lcm(int a, int b) {
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

    int n = 1000000000, a = 2, b = 217983653, c = 336916467; // 1999999984
                                                             //    int num = 16;
    //    cout << std::lcm(a, b) << endl;
    //    cout << std::lcm(a, c) << endl;
    //    cout << std::lcm(b, c) << endl;

    //    long long count_ugly = num / a + num / b + num / c - num / std::lcm(a, b) - num / std::lcm(b, c) - std::lcm(a, c) + std::lcm(std::lcm(a, b), c);
    //    cout << count_ugly << endl;

    cout << solution.nthUglyNumber(n, a, b, c) << endl;

    return 0;
}