#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution40 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {

public:
    // **去重:排序+判断
    // 剪枝
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;

        //[i..n-1]选
        function<void(int, int)> dfs = [&](int start, int sum) {
            if (sum == 0) {
                ans.push_back(path);
                return;
            }
            for (int j = start; j < n && sum - candidates[j] >= 0; ++j) { // 排序+剪枝，后续都不满足
                if (j > start && candidates[j] == candidates[j - 1]) {    // 剪枝，避免同层重复
                    continue;
                }
                path.push_back(candidates[j]);
                dfs(j + 1, sum - candidates[j]);
                path.pop_back();
            }
        };

        dfs(0, target);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution40

using namespace solution40;
int main() {
    std::cout << "Leetcode "
              << "40" << std::endl;
    Solution solution;

    return 0;
}