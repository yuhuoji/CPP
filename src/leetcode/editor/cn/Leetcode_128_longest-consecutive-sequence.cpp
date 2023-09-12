#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution128 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_set<int> num_set; // hashset去重，降复杂度O(1)
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestLength = 0;

        for (const int& num : nums) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentlength = 1;
                while (num_set.count(currentNum + 1)) {
                    currentNum++;
                    currentlength++;
                }
                longestLength = max(longestLength, currentlength);
            }
        }
        return longestLength;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution128

using namespace solution128;
int main() {
    std::cout << "Leetcode " << 128 << std::endl;
    Solution solution = Solution();
//        vector<int> nums = {100, 4, 200, 1, 3, 2};
    vector<int> nums = {1, 2, 0, 1};
    cout << solution.longestConsecutive(nums) << endl;

    return 0;
}