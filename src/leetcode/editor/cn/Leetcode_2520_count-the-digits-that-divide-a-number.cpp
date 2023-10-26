#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2520 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        for (int t = num; t; t /= 10) {
            ans += num % (t % 10) == 0 ? 1 : 0;
        }
        return ans;
    }

    // 字符串遍历
    int countDigits1(int num) {
        int cnt = 0;
        string s = to_string(num);
        for (const auto& c : s) {
            if (num % (c - '0') == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2520

using namespace solution2520;
int main() {
    std::cout << "Leetcode "
              << "2520" << std::endl;
    Solution solution;

    return 0;
}