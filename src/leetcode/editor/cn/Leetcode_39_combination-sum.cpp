#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution39 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 时间, 所有可行解的长度之和, n 个位置每次考虑选或者不选, O(n*2^n)
    // 空间O(target)
    // 可以排序+剪枝
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 排不排序都能AC
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;

        // 从[0..]里选
        function<void(int, int)> dfs = [&](int i, int sum) {
            if (sum == 0) {
                ans.push_back(path);
                return;
            }
            for (int j = i; j < n && sum - candidates[j] >= 0; ++j) {
                path.push_back(candidates[j]);
                dfs(j, sum - candidates[j]);
                path.pop_back();
            }
        };

        dfs(0, target);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution39

using namespace solution39;
int main() {
    std::cout << "Leetcode "
              << "39" << std::endl;
    Solution solution;

    return 0;
}