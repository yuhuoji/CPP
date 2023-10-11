//
// Created by Legion on 2023/10/10.
//

#include <bits/stdc++.h>

using namespace std;
// 邻接表存储图

class Solution {
public:
    const int INF = 0x3f3f3f3f; // 表示无穷大, 且满足无穷大+无穷大=无穷大, 不会溢出
    void dijkstra(vector<vector<int>> graph, int n, int s) {
        vector<int> dis(n, INF);    // 存储起点到各个点的最短距离
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
            // 用cur对其他未确定的点进行松弛操作
            for (int j = 0; j < n; j++) {
                dis[j] = min(dis[j], dis[cur] + graph[cur][j]); // 用t更新其他点
            }
        }
        // 输出结果
        for (int i = 0; i < n; i++) {
            cout << dis[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution solution;
    const int INF = 0x3f3f3f3f;
    cout << "INF : " << INF << endl;
    cout << bitset<32>(INF) << endl;

    const int NINF = -INF - 1; //0xc0c0c0c0
    cout << "NINF : " << NINF << endl;
    cout << bitset<32>(NINF) << endl;

    int array[10];
    memset(array, 0xc0, sizeof(array)); // 按字节初始化数组为最大值
    for (int i : array) {
        cout << i << " ";
    }
    cout << endl;

    int n = 4; // 点 0...5
    vector<vector<int>> graph = {{0, 1, 2, INF},
                                 {1, 0, 2, 3},
                                 {2, 2, 0, 3},
                                 {INF, 3, 3, 0}}; // 邻接矩阵存储图
    solution.dijkstra(graph, 4, 0);

    return 0;
}