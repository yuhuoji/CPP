#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution73 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 空间O(1)
    //  用第一行第一列更新其他行列（记录0的位置），然后用其他行列更新第一行第一列(需要记录开始第一行第一列是否含有0)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag_row0 = false, flag_col0 = false;
        // 记录
        for (int i = 0; i < m; ++i) { // 第一列
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }

        // 其他行列更新第一行列
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // 第一行和第一列更新其他
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 最后更新第一行和第一列自己
        if (flag_row0) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }

    // 空间o(m+n)
    void setZeroes1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    row[i] = 1;
                    col[i] = 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution73

using namespace solution73;
int main() {
    std::cout << "Leetcode "
              << "73" << std::endl;
    Solution solution;

    return 0;
}