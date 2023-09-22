#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution213 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //
    // 环形依赖 通过nums[0]转换为非环依赖
    // case1 考虑偷nums[0], 可偷[0, n-2] 偷前i间 f(i) = max{f(i-1), nums[i-1] + f(i-2)}, i from 1 to n-2
    // case2 不考虑偷nums[0], 可偷[1, n-1] 偷前i间 f(i) = max{f(i-1), nums[i-1] + f(i-2)}, i from 1 to n-1
    // case1 ^ case2 = 不偷[0]且不偷[n-1] != null
    int rob(vector<int>& nums) {
        int n = (int)nums.size(); // n>=1
        if (n == 1) {
            return nums[0];
        }
        int case1 = robRange(nums, 0, n - 2);
        int case2 = robRange(nums, 1, n - 1);
        return max(case1, case2);
    }

    // [start, end]
    int robRange(const vector<int>& nums, int start, int end) {
        int first = 0;
        int second = nums[start];
        int money = second;
        for (int i = start + 1; i <= end; ++i) { //[start+1 ... end]
            money = max(second, nums[i] + first);
            first = second;
            second = money;
        }
        return money;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution213

using namespace solution213;
int main() {
    std::cout << "Leetcode "
              << "213" << std::endl;
    Solution solution = Solution();
    //[1,2,3]
    vector<int> nums = {1, 2, 3};
    cout << solution.rob(nums) << endl;
    return 0;
}