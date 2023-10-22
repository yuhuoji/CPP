#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution560 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 前缀和 + 哈希表

    // REVIEW @date 2023-10-22

    // 前缀和，0~i的前缀和sum, 看是否存在sum-k
    // 哈希表优化，查找前缀和(sum-k)这个过程
    int subarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // 前缀和-次数
        int cnt = 0;
        mp[0] = 1;   // ！！！前缀和为0最开始就存在
        int sum = 0; // 当前的前缀和
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) { // 存在
                cnt+=mp[sum-k]; //统计所有前缀和为(sum-k)的
            }
            mp[sum]++; // 记录当前的前缀和
        }
        return cnt;
    }

    // 前缀和pre, 看是否有(pre-k),
    // 则pre - (pre-k) = k
    // pre[i] - pre[j-1] = k
    int subarraySum2(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp; // 累加和-出现次数
        // sum [start...end] = sum[end] - sum[start-1] = k
        // sum[i] 0~i的和
        mp[0] = 1;   // 0这个累加和有一次
        int sum = 0; // 前缀和
        for (auto num : nums) {
            sum += num;                         // 0~当前位置的和
            if (mp.find(sum - k) != mp.end()) { // sum - (sum-k) = k，有这个累加和
                ans += mp[sum - k];
            }
            mp[sum]++;
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

    vector<int> nums = {1};
    int k = 0;
    int ans = solution.subarraySum(nums, k);
    cout << ans << endl;
    return 0;
}