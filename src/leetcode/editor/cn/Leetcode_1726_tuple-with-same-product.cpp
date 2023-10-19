#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1726 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto& [k, v] : mp) {
            ans += v * (v - 1) / 2 * 8;
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution1726

using namespace solution1726;
int main() {
    std::cout << "Leetcode "
              << "1726" << std::endl;
    Solution solution;

    return 0;
}