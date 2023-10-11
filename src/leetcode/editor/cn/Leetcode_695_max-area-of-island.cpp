#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

  
namespace solution695{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(const vector<vector<int>>& grid, int r, int c, int& num) {
        // basecase
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return;
        }
        if (grid[r][c] == 0) { // water
            return;
        }
        if (vis[r][c] == 1) { // visited
            return;
        }
        num++;         // land
        vis[r][c] = 1; // 标记为已访问过
        // 递归
        dfs(grid, r - 1, c, num);
        dfs(grid, r + 1, c, num);
        dfs(grid, r, c - 1, num);
        dfs(grid, r, c + 1, num);
    }
    vector<vector<int>> vis;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vis = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    int num = 0;
                    dfs(grid, i, j, num);
                    ans = max(ans, num);
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution695;
int main() {
    std::cout << "Leetcode " << "695" << std::endl;
    Solution solution;

    return 0;
}