#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution46 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 时间复杂度 O(n*n!)
    // 叶节点个数*路径长度
    // 复制 O(n)
    // 空间复杂度 O(n)

    // 集合记录
    // REVIEW @date 2023-10-30
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n);

        set<int> unused(nums.begin(), nums.end());

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            set<int> unused_copy = unused;
            for (auto num : unused_copy) { //枚举
                path[i] = num;
                unused.erase(num);
                dfs(i + 1);
                unused.insert(num);
            }
        };

        dfs(0);
        return ans;
    }

    // 用bool数组记录
    vector<vector<int>> permute1(vector<int>& nums) {
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