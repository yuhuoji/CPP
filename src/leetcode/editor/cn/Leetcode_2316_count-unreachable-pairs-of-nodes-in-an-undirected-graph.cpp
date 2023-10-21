#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2316 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-21 并查集

    // dfs
    // 统计每个点的连通分量
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); // 邻接表
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        // dfs, 统计当前点的联通分量
        function<int(int)> dfs = [&](int x) {
            visited[x] = 1;
            int cnt = 1;
            for (auto i : graph[x]) {
                if (!visited[i]) {
                    cnt += dfs(i);
                }
            }
            return cnt;
        };

        long long res = 0;
        // 遍历所有点，统计联通分量
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                long long cnt = dfs(i);
                res += cnt * (n - cnt) * 1ll;
            }
        }
        return res / 2;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2316

using namespace solution2316;
int main() {
    std::cout << "Leetcode "
              << "2316" << std::endl;
    Solution solution;

    return 0;
}