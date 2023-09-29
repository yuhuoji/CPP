#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution15 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 不重复
                continue;
            }
            if (i + 2 < n && nums[i] + nums[i + 1] + nums[i + 2] > 0) { // 优化1，nums中最小的组合
                break;
            }
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) { // 优化2，对当前i最大的组合
                continue;
            }
            int k = n - 1;
            int target = -nums[i]; // b + c = -a
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) { // 不重复
                    continue;
                }
                while (j < k && nums[j] + nums[k] > target) { // nums[k]从右向左找
                    --k;
                }
                if (j == k) { // 后续j > k不存在合适的ijk
                    break;
                }
                if (nums[j] + nums[k] == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }

    // 官方
    vector<vector<int>> threeSum2(vector<int>& nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 不重复
                continue;
            }
            int k = n - 1;
            int target = -nums[i]; // b + c = -a
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) { // 不重复
                    continue;
                }
                while (j < k && nums[j] + nums[k] > target) { // nums[k]从右向左找
                    --k;
                }
                if (j == k) { // 后续j > k不存在合适的ijk
                    break;
                }
                if (nums[j] + nums[k] == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum1(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 1; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                for (int k = j + 1; k < n; ++k) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution15

using namespace solution15;
int main() {
    std::cout << "Leetcode "
              << "15" << std::endl;
    Solution solution;
    //    [-1,0,1,2,-1,-4]
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = solution.threeSum(nums);
    for (auto item : ans) {
        for (auto num : item) {
            cout << num << ", ";
        }
        cout << endl;
    }
    return 0;
}