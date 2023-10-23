#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2910 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // REVIEW @date 2023-10-23 不会做
    //  贪心
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> mp; // 每个数字出席拿了几次
        for (int num : nums) {
            mp[num]++;
        }
        // 最少的次数
        int k = min_element(mp.begin(), mp.end(),
                            [](const auto& a, const auto& b) {
                                return a.second < b.second;
                            })
                    ->second;

        for (;; --k) {
            int ans = 0;
            for (auto& [_, c] : mp) {
                // q < r
                if (c / k < c % k) {
                    ans = 0;
                    break;
                }
                ans += (c + k) / (k + 1); // ceil(c/(k+1))
            }
            if (ans) {
                return ans;
            }
        }
        return 0;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2910

using namespace solution2910;
int main() {
    std::cout << "Leetcode "
              << "2910" << std::endl;
    Solution solution;

    return 0;
}