#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution377 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-29 dp

    //backtracking TLE
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        function<void(int)> dfs = [&](int sum) {
            if (sum == 0) {
                ans++;
                return;
            }
            for (int j = 0; j < n; ++j) { // 枚举所有，剪枝
                if (sum-nums[j]<0){
                    return;
                }
                dfs(sum - nums[j]);
            }
        };

        dfs(target);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution377

using namespace solution377;
int main() {
    std::cout << "Leetcode "
              << "377" << std::endl;
    Solution solution;

    vector<int> nums = {1,2,3};
    int target = 32;
    cout << solution.combinationSum4(nums,target) << endl;

    return 0;
}