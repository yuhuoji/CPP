#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution41 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-06 难
    // 双指针
    // nums[i]位置放i+1
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n;
        while (l < r) {
            if (nums[l] == l + 1) { // l位置已经放好
                l++;
            } else if (nums[l] <= l                    // l左侧已经放好
                       || nums[l] > r                  // 当前只可能排好1...r，nums[l]没用
                       || nums[nums[l] - 1] == nums[l] // nums[l]的数在nums[l] - 1位置已经放好，即nums[nums[l] - 1]
            ) {
                r--;
                swap(nums[l], nums[r]);
            } else { // 交换
                swap(nums[l], nums[nums[l] - 1]);
            }
        }
        return l + 1;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution41

using namespace solution41;
int main() {
    std::cout << "Leetcode "
              << "41" << std::endl;
    Solution solution;

    return 0;
}