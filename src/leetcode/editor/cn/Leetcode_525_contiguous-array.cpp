#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution525 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-22
    // sum[j]-sum[i]=0 的最长子数组
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0; // 统计0和1的数量
        int max_len = 0;
        unordered_map<int, int> mp;   // 记录第一个出现下标
        mp[0] = -1;                   // 和为0的第一个下标为-1
        for (int i = 0; i < n; ++i) { // 枚举i
            nums[i] == 0 ? sum-- : sum++;
            if (mp.count(sum)) {
                int pre_i = mp[sum];
                max_len = max(max_len, i - pre_i);
            } else {
                mp[sum] = i;
            }
        }
        return max_len;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution525

using namespace solution525;
int main() {
    std::cout << "Leetcode "
              << "525" << std::endl;
    Solution solution;

    return 0;
}