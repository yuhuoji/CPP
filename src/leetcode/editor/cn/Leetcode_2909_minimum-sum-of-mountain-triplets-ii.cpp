#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2909 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //前后缀分解
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> lMax(n); //[0...i]最小值
        vector<int> rMax(n); // 递减
        lMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            lMax[i] = min(lMax[i - 1], nums[i]);
        }
        rMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rMax[i] = min(rMax[i + 1], nums[i]);
        }

        // 元素和最小
        int minSum = INT_MAX;

        for (int j = 1; j < n - 1; ++j) { // 枚举j
            if (lMax[j - 1] < nums[j] && nums[j] > rMax[j + 1]) {
                minSum = min(minSum, lMax[j - 1] + nums[j] + rMax[j + 1]);
            }
        }

        return minSum == INT_MAX ? -1 : minSum; // 不存在
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2909

using namespace solution2909;
int main() {
    std::cout << "Leetcode "
              << "2909" << std::endl;
    Solution solution;

    vector<int> nums = {6,5,4,3,4,5};
    cout << solution.minimumSum(nums) << endl;

    return 0;
}