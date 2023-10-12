#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution410 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-12
    // 二分
    // 单调性:
    // 分成k份
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;  //部分和的最大值
        int sum = 0, max_num = 0;
        for (auto num : nums) {
            max_num = max(max_num, num);
            sum += num;
        } // 1 <= k <= min(50, nums.length), 最大和最大可能为sum, 二分范围[max, sum], k=1 k=n
        int l = max_num;
        int r = sum;
        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            int part = splitPart(nums, m); // 每份和不超过m，分成part份，都满足份数part<=k
            if (part <= k) { //满足，记录答案，并尝试部分和能否更小
                ans = m;
                r = m - 1;
            } else { //不满足，尝试和更大能否满足
                l = m + 1;
            }
        }
        return ans;
    }

    // 每部分和不超过limit，返回最小分成的数量
    // limit变大，则part只可能变小
    int splitPart(const vector<int>& nums, long limit) {
        int part = 1;
        int sum = 0; // 1000*10^6
        for (auto num : nums) {
            if (sum + num > limit) { // 超出，需要新分一个数组
                part++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return part;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution410

using namespace solution410;
int main() {
    std::cout << "Leetcode "
              << "410" << std::endl;
    Solution solution;

    return 0;
}