#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution238 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
    // 前后缀分解

    //pre[i] i左侧所有乘积
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1); //suf[n-1]=1 右侧没有元素
        for (int i = n - 2; i >= 0; --i) {
            ans[i] = ans[i + 1] * nums[i + 1];
        }
        int pre = nums[0]; //可以简化
        for (int i = 1; i < n; ++i) {
            ans[i] *= pre;
            pre *= nums[i];
        }
        return ans;
    }

    vector<int> productExceptSelf1(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1), post(n, 1);
        vector<int> ans(n);
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            post[i] = post[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = pre[i] * post[i];
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution238

using namespace solution238;
int main() {
    std::cout << "Leetcode "
              << "238" << std::endl;
    Solution solution;

    return 0;
}