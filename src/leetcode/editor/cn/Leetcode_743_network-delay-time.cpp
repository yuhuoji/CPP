#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution743 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-11
    // 邻接表
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 0x3f3f3f3f;
        vector<vector<pair<int, int>>> g(n); // 长度n的邻接表, from, pair<to, weight>
        for (auto& t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }

        vector<int> dis(n, inf);
        dis[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //小根堆，维护未确定的点及其距离
        pq.emplace(0, k - 1);
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int time = p.first, x = p.second;
            if (dis[x] < time) {
                continue;
            }
            for (auto& from : g[x]) {
                int to = from.first, d = dis[x] + from.second;
                if (d < dis[to]) {
                    dis[to] = d;
                    pq.emplace(d, to);
                }
            }
        }

        int ans = *max_element(dis.begin(), dis.end());
        return ans == inf ? -1 : ans;
    }

    // 邻接矩阵
    int networkDelayTime1(vector<vector<int>>& times, int n, int k) {
        // 初始化邻接矩阵
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> graph(n, vector<int>(n, INF)); // 大小n*n的邻接矩阵
        for (auto& t : times) {
            int from = t[0] - 1, to = t[1] - 1;
            graph[from][to] = t[2];
        }

        vector<int> dis(n, INF); // 点i : dis[i-1]
        vector<int> vis(n, 0);
        dis[k - 1] = 0; // 点k是源点
        for (int i = 0; i < n; ++i) {
            int cur = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (cur == -1 || dis[cur] > dis[j])) {
                    cur = j;
                }
            }
            vis[cur] = 1;
            // 用cur对其他未确定的点进行松弛操作
            for (int j = 0; j < n; ++j) {
                dis[j] = min(dis[j], dis[cur] + graph[cur][j]);
            }
        }

        return *max_element(dis.begin(), dis.end()) == INF ? -1 : *max_element(dis.begin(), dis.end());
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution743

using namespace solution743;
int main() {
    std::cout << "Leetcode "
              << "743" << std::endl;
    Solution solution;

    vector<vector<int>> times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    int n = 3;
    int k = 1;

        cout << solution.networkDelayTime(times, n, k) << endl;
    return 0;
}