#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution974 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-22 哈希表 + 单次统计
    //REVIEW @date 2023-10-22
    // 前缀
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1; // 前缀和本身被 k 整除的情况
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int modulus = (sum % k + k) % k; // cpp负数取模
            // sum[j]和sum[i]同余k
            if (mp.count(modulus)) {
                cnt += mp[modulus];
            }
            mp[modulus]++;
        }
        return cnt;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution974

using namespace solution974;
int main() {
    std::cout << "Leetcode "
              << "974" << std::endl;
    Solution solution;

    cout << -2 % 5 << endl;
    return 0;
}