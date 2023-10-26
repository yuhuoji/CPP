#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2698 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int punishmentNumber(int n) {
        int ans = 0;

        // 枚举, 分成1~len段
        for (int i = 1; i <= n; ++i) { // 枚举
            if (check(i)) {
                ans += i * i;
            }
        }
        return ans;
    }

    // check if num is a punishment number
    bool check(int num) {
        string s = to_string(num * num);
        int len = s.length();
        int sum = num;

        // 枚举i位置
        // s有没有一种分割方法成立, 让和等于i
        // 0~i-1已经分完, 当前来到i位置
        // 回溯
        function<bool(int, int)> dfs = [&](int i, int remain) -> bool {
            if (remain < 0) {
                return false;
            }
            if (i == len) {
                if (remain == 0) {
                    return true;
                } else {
                    return false;
                }
            }

            // 当前操作分割[i..j], 下一个分割[j+1..len-1]
            for (int j = i; j < len; ++j) {
                if (dfs(j + 1, remain - std::stoi(s.substr(i, j - i + 1)))) {
                    return true;
                }
            }

            return false;
        };

        return dfs(0, sum); // 从位置0开始, 剩余和为sum
    };
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2698

using namespace solution2698;
int main() {
    std::cout << "Leetcode "
              << "2698" << std::endl;
    Solution solution;

    int n = 10;
    cout << solution.punishmentNumber(n) << endl;

    return 0;
}