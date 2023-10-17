#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution34 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {

public:
    // 二分，找到第一个 >= target的位置
    // 闭区间写法[l,r]
    // *第一个>=target的位置
    // 四种可以相互转换(整数)
    // 最后一个<target的位置 binarySearch(>=target) - 1
    // 第一个>target的位置 binarySearch(>=target+1)
    // 最后一个<=target的位置, 转换成binarySearch(>target) - 1, binarySearch(>=target+1) - 1
    int binarySearch(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) { // 最后一次循环
            int m = ((r - l) >> 1) + l;
            if (target > nums[m]) {
                l = m + 1; //[l-1]一定小于target
            } else {
                r = m - 1; //[r+1]一定大于等于target
            }
        }
        // 循环结束r+1=l
        // r表示最后一个小于target的位置，l表示第一个大于等于target的位置
        return l; // 返回第一个大于等于target的位置
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
    int target = 7;

    // 第一个>=target
    int ans = solution.binarySearch(nums, target);
    cout << "position : " << solution.binarySearch(nums, target) << ", ans : " << nums[solution.binarySearch(nums, target)] << endl;

    // 第一个>target
    cout << "position : " << solution.binarySearch(nums, target + 1) << ", ans : " << nums[solution.binarySearch(nums, target + 1)] << endl;

    // 最后一个<=target
    cout << "position : " << solution.binarySearch(nums, target + 1) - 1 << ", ans : " << nums[solution.binarySearch(nums, target + 1) - 1] << endl;

    // 最后一个<target
    cout << "position : " << solution.binarySearch(nums, target) - 1 << ", ans : " << nums[solution.binarySearch(nums, target) - 1] << endl;

    return 0;
}