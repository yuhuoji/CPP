#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution72 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // 插入和删除等效
    //  dp
    //  dfs(i,j) = dfs(i-1, j-1) when s[i]=t[j]
    //  dfs(i,j) = min{单词1删除一个字符dfs(i-1, j), 单词2增加一个字符dfs(i, j-1), 替换dfs(i-1, j-1)} when s[i]!=t[j]
public:
    // 空间压缩
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 初始化第一行第一列
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j + 1] = word1[i] == word2[j] ? dp[i][j] : min(min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]) + 1;
            }
        }
        return dp[m][n];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution72

using namespace solution72;
int main() {
    std::cout << "Leetcode "
              << "72" << std::endl;
    Solution solution;

    return 0;
}