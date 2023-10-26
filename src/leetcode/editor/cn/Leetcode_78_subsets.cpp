#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution78 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //REVIEW @date 2023-10-26

    // 答案视角
    // 每个节点都是答案
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int)> dfs = [&](int i) {
            ans.push_back(path);
            if (i == n) {
                return;
            }
            for (int j = i; j < n; ++j) { // 枚举当前点的数字，j>=i
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back(); // 恢复现场
            }
        };

        dfs(0);
        return ans;
    }

    // 输入视角
    // 每次选or不选，每个路径都是答案
    vector<vector<int>> subsets1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;

        // 每次选or不选
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(path); // 用引用可以改变ans.push_back(std::ref(path));
                return;
            }
            dfs(i + 1); // 不选i

            // 选i
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back(); // 恢复现场
        };

        dfs(0);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution78

using namespace solution78;
int main() {
    std::cout << "Leetcode "
              << "78" << std::endl;
    Solution solution;

    return 0;
}