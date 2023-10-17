#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution153 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        // 闭区间[l,r]
        while (l < r) {
            int m = ((r - l) >> 1) + l;
            if (nums[m] <= nums[n - 1]) { // 判断m在最小值的左侧还是右侧
                // m在右面一段，最小值在左侧
                r = m; // m可能是最小值
            } else {
                // m在左面一段
                l = m + 1; // m一定不是最小值
            }
        }
        return nums[l];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution153

using namespace solution153;
int main() {
    std::cout << "Leetcode "
              << "153" << std::endl;
    Solution solution;

    return 0;
}