#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution53 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 前后缀分解O(N^2)
    // 以i位置结尾的最大和dp[i] = max{dp[i-1] + nums[i], nums[i]}

    // dp[i]只与dp[i-1]相关，压缩空间
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int f = 0; // 存上一个状态
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            int t = max(f + nums[i], nums[i]);
            ans = max(ans, t);
            f = t;
        }
        return ans;
    }

    int maxSubArray1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); // 0..n-1
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution53

using namespace solution53;
int main() {
    std::cout << "Leetcode "
              << "53" << std::endl;
    Solution solution;

    return 0;
}