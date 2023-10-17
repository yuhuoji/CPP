#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution33 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // REVIEW @date 2023-10-17
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        //[l,r]
        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            // nums[0] nums[m] nums[n-1]
            if (nums[m] == target) {
                return m;
            }
            if (nums[0] <= nums[m]) {                        // m在第一段
                if (nums[0] <= target && target < nums[m]) { // 0 target m
                    r = m - 1;
                } else { //target在第二段
                    l = m + 1;
                }
            } else { //m在第二段
                if (nums[m] < target && target <= nums[n - 1]) { //m target n-1
                    l = m + 1;
                } else { //target在第一段
                    r = m - 1;
                }
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution33

using namespace solution33;
int main() {
    std::cout << "Leetcode "
              << "33" << std::endl;
    Solution solution;

    return 0;
}