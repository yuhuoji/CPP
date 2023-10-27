#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution46 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n);
        vector<bool> on_path(n); // n

        // 当前操作:排path[i], path[0..i-1]排好
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!on_path[j]) { // 不重复使用
                    path[i] = nums[j];
                    on_path[j] = true;
                    dfs(i + 1);
                    on_path[j] = false;
                }
            }
        };

        dfs(0);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution46

using namespace solution46;
int main() {
    std::cout << "Leetcode "
              << "46" << std::endl;
    Solution solution;

    vector<int> nums{1, 2, 3};
    auto ans = solution.permute(nums);
    for (auto& v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}