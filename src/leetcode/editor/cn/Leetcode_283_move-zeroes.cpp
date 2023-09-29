#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution283 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int fast = 0, slow = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution283

using namespace solution283;
int main() {
    std::cout << "Leetcode "
              << "283" << std::endl;
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (int num : nums) {
        cout << num << ", ";
    }
    cout << endl;
    return 0;
}