#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution287 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 与单链表是否有环相同
    // 双指针
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            //越界
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        // 第一次相遇
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution287

using namespace solution287;
int main() {
    std::cout << "Leetcode "
              << "287" << std::endl;
    Solution solution;
    //    nums = [1,3,4,2,2]
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << solution.findDuplicate(nums) << endl;

    return 0;
}