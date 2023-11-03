#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1143 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // dp
    // dfs(i,j) = dfs(i-1,j-1) when s[i]=t[j]
    // dfs(i,j) = max{dfs(i-1,j), dfs(i,j-1)} when s[i]!=t[j]
public:

    // 空间压缩成一个数组
    // 空间M
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int> cur(m + 1, 0);

        for (int i = 0; i < n; ++i) {
            int pre = cur[0]; // 存储左上方的元素
            for (int j = 0; j < m; ++j) {
                int t = cur[j + 1];
                cur[j + 1] = text1[i] == text2[j] ? pre + 1 : max(cur[j + 1], cur[j]);
                pre = t;
            }
        }

        return cur[m];
    }

    // 空间压缩成两个一维数组
    // 空间2M
    int longestCommonSubsequence3(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int> pre(m + 1);
        vector<int> cur(m + 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cur[j + 1] = text1[i] == text2[j] ? pre[j] + 1 : max(pre[j + 1], cur[j]);
            }
            swap(pre, cur);
        }

        return pre[m];
    }

    // 改成dp
    // 时间O(M*N)
    // 空间O(M*N)
    int longestCommonSubsequence2(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // 防止负数下标，加一位
                                                              // i=0 or j=0 为0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i + 1][j + 1] = text1[i] == text2[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
                //                if (text1[i] == text2[j]) {
                //                    dp[i + 1][j + 1] = dp[i][j] + 1;
                //                } else {
                //                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                //                }
            }
        }

        return dp[n][m];
    }

    // 递归
    int longestCommonSubsequence1(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        function<int(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0) {
                return 0;
            }
            if (text1[i] == text2[j]) {
                return dfs(i - 1, j - 1) + 1;
            } else {
                return max(dfs(i - 1, j), dfs(i, j - 1));
            }
        };

        return dfs(n - 1, m - 1);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution1143

using namespace solution1143;
int main() {
    std::cout << "Leetcode "
              << "1143" << std::endl;
    Solution solution;

    return 0;
}