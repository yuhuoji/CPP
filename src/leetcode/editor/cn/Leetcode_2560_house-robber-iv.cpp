#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2560 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 二分查找，最小化最大or最大化最小
    //REVIEW @date 2023-10-15 状态压缩部分有点乱
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX / 2;

        // 窃取能力mx能不能偷够k间房子
        function<bool(int)> check = [&nums, k](int limit) -> bool {
            // 0...n-1
            // 选nums[i] <= limit, fi = fi-2 + 1
            // 不选 fi = fi-1
            // max{case1, case2}
            int n = nums.size();
            int f0 = 0, f1 = 0;
            for (int i = 0; i < n; ++i) { // f0 f1 cur
                if (nums[i] <= limit) {   // 选
                    int cur = max(f0 + 1, f1);
                    f0 = f1;
                    f1 = cur;
                } else {
                    f0 = f1;
                }
            }
            return f1 >= k;
        };

        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            if (check(m)) { // m能，比m大的一定也能
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2560

using namespace solution2560;
int main() {
    std::cout << "Leetcode "
              << "2560" << std::endl;
    Solution solution;

    vector<int> nums = {2, 3, 5, 9};
    int k = 2;
    cout << solution.minCapability(nums, k) << endl;

    return 0;
}