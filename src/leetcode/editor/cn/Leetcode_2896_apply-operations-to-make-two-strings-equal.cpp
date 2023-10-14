#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2896 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // REVIEW @date 2023-10-14
    //  dp
public:
    //共有-1...m-1个状态, 右移一位
    int minOperations(string s1, string s2, int x) {
        if (count(s1.begin(), s1.end(), '1') % 2 != count(s2.begin(), s2.end(), '1') % 2) {
            return -1;
        }
        int n = s1.size();
        vector<int> p; // 不同位置的下标
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                p.push_back(i);
            }
        }
        if (p.size() % 2) {
            return -1;
        } else if (p.size() == 0) {
            return 0;
        }
        //滚动数组
        int f0, f1 = x; //-1, 0
        for (int i = 1; i < p.size(); ++i) {
            int new_f = min(f1 + x, f0 + (p[i] - p[i - 1]) * 2);
            f0 = f1;
            f1 = new_f;
        }
        return f1 / 2;
    }

    // 时间O(N)
    int minOperations2(string s1, string s2, int x) {
        if (count(s1.begin(), s1.end(), '1') % 2 != count(s2.begin(), s2.end(), '1') % 2) {
            return -1;
        }
        int n = s1.size();
        vector<int> diff; // 不同位置的数组
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                diff.emplace_back(i);
            }
        }
        int m = diff.size(); // 存储不同位置的数组
        if (m == 0) {        // 相等
            return 0;
        }
        if (m % 2 == 1) { // 奇数，无解
            return -1;
        }

        // TODO @date 2023-10-14
        //  当前i位置
        //  op1 dfs(i-1)+x/2
        //  op2 dfs(i-2)+diff[i]-diff[i-1]
        //  将花费先乘2最后除2，避免x/2
        function<int(int)> dfs = [&x, &diff](int i) {
            function<int(int)> solve = [&](int i) -> int {
                if (i == -1) {
                    return 0;
                }
                if (i == 0) { // 特判i=0
                    return x;
                }
                return min(solve(i - 1) + x, solve(i - 2) + (diff[i] - diff[i - 1]) * 2);
            };
            return solve(i);
        };

        return dfs(m - 1) / 2; //-1...m-1个状态
    }

    // 记忆化搜索 O(n^2)
    int minOperations1(string s1, string s2, int x) {
        // 操作1和操作2不会改变不同位的奇偶数，一定为偶数
        // 无解
        if (count(s1.begin(), s1.end(), '1') % 2 != count(s2.begin(), s2.end(), '1') % 2) {
            return -1;
        }

        int n = s1.size();

        // 定义lambda表达式
        // 如果使用auto推断类型不能自我调用
        // 从后往前，n-1...0
        // 当前位置i
        // 现在有的可以无花费反转一个位置的次数j（将操作1分成两部分 = x花费调整一个位置+免费调整一个位置）
        // 前一个位置是否需要调整
        function<int(int, int, bool)> dfs = [&](int i, int j, bool pre_rev) {
            if (i < 0) {                // base case
                if (j > 0 || pre_rev) { // 已经结束了还需要修改之前的
                    return INT_MAX / 2;
                } else {
                    return 0;
                }
            }
            if ((s1[i] == s2[i]) == !pre_rev) { // 当前位已经相等且不用反转，或当前位不等且当前位需要反转（前一位反转了）
                return dfs(i - 1, j, false);
            }
            // 不相等
            int res1 = dfs(i - 1, j + 1, false) + x; // operation1
            int res2 = dfs(i - 1, j, true) + 1;      // operation2
            int res = min(res1, res2);
            if (j > 0) {
                int res3 = dfs(i - 1, j - 1, false);
                res = min(res, res3);
            }
            return res;
        };

        // 从n-1位置，免费次数，前一个位置不反转
        return dfs(n - 1, 0, false);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2896

using namespace solution2896;
int main() {
    std::cout << "Leetcode "
              << "2896" << std::endl;
    Solution solution;
    string s1 = "11111001100111101010101010100000010000000010110100111000001100101100000010000011100";
    string s2 = "11101101001010101001000110010101011001100110011011001101100100101101100101100000010";
    int x = 50;
    cout << solution.minOperations(s1, s2, x) << endl;
    return 0;
}