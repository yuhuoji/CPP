#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution11 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 双指针
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution11

using namespace solution11;
int main() {
    std::cout << "Leetcode "
              << "11" << std::endl;
    Solution solution;

    return 0;
}