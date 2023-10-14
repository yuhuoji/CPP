#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution719 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        sort(nums.begin(), nums.end());
        int r = nums[n - 1];
        int ans = -1;
        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            if (check(nums, m) >= k) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    // nums中小于等于distance的有几个
    // 滑动窗口
    int check(const vector<int>& nums, int distance) {
        int cnt = 0;
        int n = nums.size();
        for (int l = 0, r = 0; l < n; ++l) {
            while (r + 1 < n && nums[r + 1] - nums[l] <= distance) {
                r++;
            }
            cnt += r - l; //[0..3] 3-0
        }
        return cnt;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution719

using namespace solution719;
int main() {
    std::cout << "Leetcode "
              << "719" << std::endl;
    Solution solution;

    return 0;
}