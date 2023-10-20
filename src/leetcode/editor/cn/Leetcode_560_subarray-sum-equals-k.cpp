#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution560 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 滑动窗口？

    // REVIEW @date 2023-10-20
    // 前缀和pre, 看是否有(pre-k),
    // 则pre - (pre-k) = k
    // pre[i] - pre[j-1] = k
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        // sum [start...end] = pre[end] - pre[start-1] = k
        // pre[i] 0~i的和
        mp[0] = 1; // start = 0
        int pre = 0;
        for (auto num : nums) {
            pre += num;                         // 0~当前位置的和
            if (mp.find(pre - k) != mp.end()) { // pre - (pre-k) = k
                ans += mp[pre - k];
            }
            mp[pre]++;
        }
        return ans;
    }

    // 枚举, TLE
    int subarraySum1(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) { // 枚举起点
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                if (sum == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution560

using namespace solution560;
int main() {
    std::cout << "Leetcode "
              << "560" << std::endl;
    Solution solution;

    return 0;
}