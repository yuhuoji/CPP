#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution136 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 位运算
    // a^a = 0
    // a^b = 1
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution136

using namespace solution136;
int main() {
    std::cout << "Leetcode "
              << "136" << std::endl;
    Solution solution;

    return 0;
}