#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution523 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //要求最长子数组, 只记录第一个出现的下标
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // 存储第一个出现的下标
        mp[0] = -1;                 // 余数为0，[0, j]的前缀和整除k
        // long long sum = 0;       // 前缀和
        int remainder = 0;          // 只记录余数
        for (int i = 0; i < n; ++i) {
            // sum += nums[i];
            remainder = (remainder + nums[i]) % k;
            // 看是否同余
            if (mp.count(remainder)) {
                int pre_i = mp[remainder]; // 第一次出现的下标
                if (i - pre_i >= 2) {    //[pre_index + 1, i]
                    return true;
                }
            } else { // 第一次出现
                mp[remainder] = i;
            }
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution523

using namespace solution523;
int main() {
    std::cout << "Leetcode "
              << "523" << std::endl;
    Solution solution;

    return 0;
}