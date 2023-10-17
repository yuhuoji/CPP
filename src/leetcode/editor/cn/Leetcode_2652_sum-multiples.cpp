#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2652 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 直接算会有重复的，如3和5的倍数
    int sumOfMultiples(int n) {
        // 3 5 7 15 21 35 105
        // 容斥原理
        return s(n, 3) + s(n, 5) + s(n, 7) - s(n, 15) - s(n, 21) - s(n, 35) + s(n, 105);
    }
    //[1, n] 可以被m整除的数的和
    int s(int n, int m) {
        return m * (n / m) * (n / m + 1) / 2; // 注意运算顺序，(n / m)
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2652

using namespace solution2652;
int main() {
    std::cout << "Leetcode "
              << "2652" << std::endl;
    Solution solution;
    // 测试用例: 15 测试结果 : 96 期望结果 : 81
    int n = 15;
    cout << solution.sumOfMultiples(n) << endl;
    return 0;
}