#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution200 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-11
    //  并查集

    // bfs
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vis = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    ans++;

                    vis[i][j] = 1; // 标记为已访问过
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上下左右四个方向
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        int r = p.first, c = p.second;
                        for (int k = 0; k < 4; ++k) { // bfs四个方向
                            int nr = r + dirs[k][0], nc = c + dirs[k][1];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1' && vis[nr][nc] == 0) {
                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

    // dfs
    int numIslands1(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vis = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    vector<vector<int>> vis;
    void dfs(const vector<vector<char>>& grid, int r, int c) {
        // basecase
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return;
        }
        if (grid[r][c] == '0') { // water
            return;
        }
        if (vis[r][c] == 1) { // visited
            return;
        }
        vis[r][c] = 1; // 标记为已访问过
        // 递归
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution200

using namespace solution200;
int main() {
    std::cout << "Leetcode "
              << "200" << std::endl;
    Solution solution;

    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << solution.numIslands(grid) << endl;

    return 0;
}