#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution209 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 滑动窗口，同向双指针
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1; // 取min
        int sum = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum >= target) { //单调性，sum不断变小
                ans = min(ans, r - l + 1); // l=r时长度为1
                sum -= nums[l];
                l++;
            }
        }
        return ans <= n ? ans : 0;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution209

using namespace solution209;
int main() {
    std::cout << "Leetcode "
              << "209" << std::endl;
    Solution solution;

    return 0;
}