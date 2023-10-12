#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution35 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = n;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] >= target) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    // 循环结束时l和r表示什么？
    // 在一个有序数组中找第一个大于等于 target 的下标
    int searchInsert1(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (target <= nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        // 根据if的判断条件，left左边的值一直保持小于target，right右边的值一直保持大于等于target
        //  ...(左侧<target) r l （右侧>=target）...

        return r;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution35

using namespace solution35;
int main() {
    std::cout << "Leetcode " << 35 << std::endl;
    Solution solution = Solution();
    vector<int> nums = {1, 3, 3, 5};
    int target = 3; // 2 7
    cout << solution.searchInsert(nums, target) << endl;
    return 0;
}