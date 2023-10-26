#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution77 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //时间复杂度 高度*叶节点数目=O(k * C_n^k)
    // 剪枝 path=k
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;

        // 从[1..i]中选
        function<void(int)> dfs = [&](int i) {
            int n = path.size();
            if (i < k - n) { //不够选
                return;
            }
            if (n == k) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j >= 1; --j) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }
        };

        dfs(n); //[1..n]
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution77

using namespace solution77;
int main() {
    std::cout << "Leetcode "
              << "77" << std::endl;
    Solution solution;

    return 0;
}