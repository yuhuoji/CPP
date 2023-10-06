#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution922 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return nums;
        }
        int even = 0;
        int odd = 1;
        // even, odd, n-1
        while (even <= n - 1 && odd <= n - 1) {
            if (nums[n - 1] % 2 == 0) {
                swap(nums[even], nums[n - 1]);
                even += 2;
            } else {
                swap(nums[odd], nums[n - 1]);
                odd += 2;
            }
        }
        return nums;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution922

using namespace solution922;
int main() {
    std::cout << "Leetcode "
              << "922" << std::endl;
    Solution solution;
    // nums = [4,2,5,7]
    vector<int> nums = {4, 2, 5, 7};
    vector<int> ans = solution.sortArrayByParityII(nums);
    for (auto& v : ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}