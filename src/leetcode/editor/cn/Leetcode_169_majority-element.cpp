#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution169 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // > n/2
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution169

using namespace solution169;
int main() {
    std::cout << "Leetcode "
              << "169" << std::endl;
    Solution solution = Solution();

    return 0;
}