#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution79 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //回溯+矩阵

    // 时间,远小于O(MN * 3^l)
    // 空间 visited数组O(MN) + 栈O(min{l, MN})
    bool exist(vector<vector<char>>& board, const string& word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.length();

        //vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 四个方向

        // 尝试position位置是否可以
        function<bool(int, int, int, vector<vector<int>>&)> dfs = [&](int i, int j, int position, vector<vector<int>>& visited) {
            if (board[i][j] != word[position]) {
                return false;
            }
            if (position == len - 1) { // 最后一位存在
                return true;
            }
            visited[i][j] = true;
            bool ans = false;
            for (const auto& direct : direction) { // 四个方向
                int next_i = i + direct.first;
                int next_j = j + direct.second;
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) { // 越界
                    continue;
                }
                if (visited[next_i][next_j]) { // 已经走过
                    continue;
                }
                if (dfs(next_i, next_j, position + 1, visited)) { // 找全单词
                    ans = true;
                    break;
                }
            }
            visited[i][j] = false; // 恢复现场
            return ans;
        };

        vector<vector<int>> visited(m, vector<int>(n, false)); // 记录走过的路

        // 从word[0]开始尝试
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (dfs(row, col, 0, visited)) { // 从0位置开始查找
                    return true;
                }
            }
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution79

using namespace solution79;
int main() {
    std::cout << "Leetcode "
              << "79" << std::endl;
    Solution solution;

    return 0;
}