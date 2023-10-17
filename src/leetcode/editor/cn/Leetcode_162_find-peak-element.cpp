#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution162 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // nums[i] != nums[i + 1] for all valid i.
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 2; // n-1 位置一定是封顶或峰顶右侧
        //TODO @date 2023-10-17
        // [0,n-2]上二分？？
        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            if (nums[m] > nums[m + 1]) {
                r = m - 1;
            } else { // <
                l = m + 1;
            }
        }
        return l;
    }

    int findPeakElement1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int l = 0;
        int r = n - 1; // n-1 位置一定是封顶或峰顶右侧
        // [0,n-1]上二分, 其中一定含有一个峰顶
        // 闭区间[l,r]
        while (l < r) {
            int m = ((r - l) >> 1) + l;
            if (nums[m] > nums[m + 1]) {
                r = m; // m可能是峰顶，m+1一定不是峰顶
            } else {   // <
                l = m + 1;
            }
        }
        // l=r 一定是峰顶
        return l;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution162

using namespace solution162;
int main() {
    std::cout << "Leetcode "
              << "162" << std::endl;
    Solution solution;
    //    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    vector<int> nums = {1, 2, 3, 1};
    cout << solution.findPeakElement(nums) << endl;
    return 0;
}