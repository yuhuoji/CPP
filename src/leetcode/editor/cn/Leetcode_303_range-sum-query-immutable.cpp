#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution303 {
// leetcode submit region begin(Prohibit modification and deletion)
class NumArray {
public:
    vector<int> pre; // 整体向右偏移一位，有n+1位
    // 前缀和数组
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre.resize(n + 1, 0); // l = 0
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
    }

    //[l, r]
    // sumRange{l, r} = pre[r+1] - pre[l], 不需要特殊处理l=0, pre[i]记录[0, i-1]的和
    int sumRange(int left, int right) {
        return pre[right + 1] - pre[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution303

using namespace solution303;
int main() {
    std::cout << "Leetcode "
              << "303" << std::endl;
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    return 0;
}