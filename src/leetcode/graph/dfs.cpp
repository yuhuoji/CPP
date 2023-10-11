//
// Created by Legion on 2023/10/11.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> grid, int r, int c) {
        // 判断 base case
        if (!inArea(grid, r, c)) {
            return;
        }
        // 如果这个格子不是岛屿，直接返回
        if (grid[r][c] != 1) {
            return;
        }
        grid[r][c] = 2; // 将格子标记为「已遍历过」

        // 访问上、下、左、右四个相邻结点
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    // 判断坐标 (r, c) 是否在网格中
    bool inArea(vector<vector<int>> grid, int r, int c) {
        return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
    solution.dfs(grid, 0, 0);

    return 0;
}