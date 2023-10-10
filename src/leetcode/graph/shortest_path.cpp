//
// Created by Legion on 2023/10/10.
//

#include <bits/stdc++.h>

using namespace std;
// 邻接表存储图

const int inf = 0x3f3f3f3f; // 表示无穷大
class Solution {
public:
    void dijkstra(vector<vector<int>> graph, int n, int s) {
        vector<int> dis(n, inf);    // 存储起点到各个点的最短距离
        vector<bool> vis(n, false); // 标记是否访问过
        dis[s] = 0;                 // 起点到自己的距离为0
        for (int i = 0; i < n; i++) {
            int cur = -1; // 找到dis中最小的
            for (int j = 0; j < n; j++) {
                if (!vis[j] && (cur == -1 || dis[cur] > dis[j])) {
                    cur = j;
                }
            }
            vis[cur] = true; // 标记为已访问
            for (int j = 0; j < n; j++) {
                dis[j] = min(dis[j], dis[cur] + graph[cur][j]); // 用t更新其他点
            }
        }
        for (int i = 0; i < n; i++) {
            cout << dis[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution solution;
    int n = 4; // 点 0...5
    vector<vector<int>> graph = {{0, 1, 2, inf},
                                 {1, 0, 2, 3},
                                 {2, 2, 0, 3},
                                 {inf, 3, 3, 0}}; // 邻接矩阵存储图
    solution.dijkstra(graph, 4, 0);
    return 0;
}