#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution34 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {

public:
    // 二分，找到第一个 >= target的位置
    int binarySearch(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    // 二分
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (nums.size() == 0 || nums[0] > target || nums[n - 1] < target) {
            return {-1, -1};
        }
        int l = binarySearch(nums, target);     // 第一个 >= target的位置
        int r = binarySearch(nums, target + 1); // 第一个 >= target+1的位置
        r--;
        if (nums[r] != target) { // 如果nums存在target，则nums[l] = target，否则nums[r] < target
            return {-1, -1};
        }
        return {l, r};
    }

    // 暴力
    vector<int> searchRange1(vector<int>& nums, int target) {
        int n = nums.size();
        if (nums.size() == 0 || nums[0] > target || nums[n - 1] < target) {
            return {-1, -1};
        }
        int l = 0;
        int r = n - 1;
        while (nums[l] < target) {
            l++;
        }
        if (nums[l] != target) {
            return {-1, -1};
        }
        // nums[l] = target
        while (nums[r] > target) {
            r--;
        }
        return {l, r};
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution34

using namespace solution34;
int main() {
    std::cout << "Leetcode "
              << "34" << std::endl;
    Solution solution = Solution();
    //    vector<int> nums = {1, 2, 3, 3, 3, 4, 6, 7};
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;

    int ans = solution.binarySearch(nums, target);
    cout << "position : " << ans << ", ans : " << nums[ans] << endl;
    vector<int> ans1 = solution.searchRange(nums, target);
    // Output: [-1,-1]
    cout << "output : [" << ans1[0] << ", " << ans1[1] << "]" << endl;
    return 0;
}