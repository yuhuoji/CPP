#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2906 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 前后缀分解
    // p[i,j] = pre[i,j] * suf[i,j]
    // pre[m*n]
    // pre[i] i之前的乘积
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> p(m, vector<int>(n));
        long long suf = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                p[i][j] = suf;
                suf = suf * grid[i][j] % MOD;
            }
        }

        long long pre = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                p[i][j] = pre * p[i][j] % MOD;
                pre = pre * grid[i][j] % MOD;
            }
        }
        return p;
    }

    vector<vector<int>> constructProductMatrix1(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> p(m, vector<int>(n));

        // i
        //[i/n, i%n], row = i/n, col = i%n
        p[m - 1][n - 1] = 1;
        // suf
        for (int i = m * n - 2; i >= 0; --i) {
            p[i / n][i % n] = 1ll * p[(i + 1) / n][(i + 1) % n] * grid[(i + 1) / n][(i + 1) % n] % MOD;
        }
        // pre
        long long pre = grid[0][0];
        for (int i = 1; i < m * n; ++i) {
            p[i / n][i % n] = 1ll * p[i / n][i % n] * pre % MOD;
            pre = 1ll * pre * grid[i / n][i % n] % MOD;
        }

        return p;
    }
    static constexpr int MOD = 12345;
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2906

using namespace solution2906;
int main() {
    std::cout << "Leetcode "
              << "2906" << std::endl;
    Solution solution;

    return 0;
}