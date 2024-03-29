#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution42 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-08
    //  单调栈，横着计算
    //  找下一个>=的数
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int h = height[i];
            while (!stk.empty() && h >= height[stk.top()]) {
                int bottom_h = height[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int diff_h = min(height[left], h) - bottom_h;
                ans += diff_h * (i - left - 1);
            }
            stk.push(i);
        }
        return ans;
    }

    int trap2(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }
        vector<int> lmax(n); //[0...i]的最大值
        lmax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            lmax[i] = max(lmax[i - 1], height[i]);
        }

        vector<int> rmax(n);
        rmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rmax[i] = max(rmax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += max(0, min(lmax[i], rmax[i]) - height[i]);
        }
        return ans;
    }

    // 双指针+单调性分析
    // 竖着计算
    int trap1(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }
        int l = 1, r = n - 2;
        int lmax = height[0], rmax = height[n - 1];
        int ans = 0;
        while (l <= r) {
            if (lmax <= rmax) { // 由左侧高度限制
                ans += max(0, lmax - height[l]);
                lmax = max(lmax, height[l]);
                l++;
            } else {
                ans += max(0, rmax - height[r]);
                rmax = max(rmax, height[r]);
                r--;
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution42

using namespace solution42;
int main() {
    std::cout << "Leetcode "
              << "42" << std::endl;
    Solution solution;

    return 0;
}