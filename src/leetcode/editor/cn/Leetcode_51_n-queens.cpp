#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution51 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-30 第二种写法

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> col(n); // 第i行的皇后在第col[i]列
        set<int> col_index;
        for (int i = 0; i < n; ++i) {
            col_index.insert(i);
        }

        function<bool(int, int)> is_valid = [&](int r, int c) {
            for (int R = 0; R < r; ++R) { //[0..r-1]
                int C = col[R];
                if (r + c == R + C || r - c == R - C) { // 左上或右上
                    return false;
                }
            }
            return true;
        };

        // 当前枚举的行号，剩余可枚举的列号
        function<void(int, set<int>&)> dfs = [&](int r, set<int>& st) {
            if (r == n) {
                vector<string> board(n);
                for (int i = 0; i < n; ++i) {
                    board[i] = string(col[i], '.') + 'Q' + string(n - 1 - col[i], '.');
                }
                ans.emplace_back(board);
                return;
            }
            for (const auto& c : st) {
                if (is_valid(r, c)) {
                    col[r] = c;
                    set<int> newSet = st;
                    newSet.erase(c);
                    dfs(r + 1, newSet);
                }
            }
        };

        dfs(0, col_index);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution51

using namespace solution51;
int main() {
    std::cout << "Leetcode "
              << "51" << std::endl;
    Solution solution;

    return 0;
}