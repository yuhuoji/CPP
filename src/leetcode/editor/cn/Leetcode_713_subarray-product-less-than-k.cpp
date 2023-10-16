#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution713 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // 0 <= k <= 10^6
        if (k <= 1) {
            return 0;
        }
        int n = nums.size();
        int ans = 0;
        int product = 1;
        for (int l = 0, r = 0; r < n; ++r) {
            product *= nums[r];
            while (product >= k) { // 单调性，sum不断变小
                product /= nums[l];
                l++;
            }
            //[l, r]
            //[l,r] [l+1,r] [l+2,r] ... [r,r]
            ans += r - l + 1; // l=r时长度为1
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution713

using namespace solution713;
int main() {
    std::cout << "Leetcode "
              << "713" << std::endl;
    Solution solution;

    return 0;
}