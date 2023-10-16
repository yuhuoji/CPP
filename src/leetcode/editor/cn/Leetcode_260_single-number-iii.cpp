#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution260 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 要求时间复杂度O(N), 空间O(1)
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xor_sum = 0; //无符号整数防止溢出
        for (auto num : nums) {
            xor_sum ^= num;
        }
        int lowbit = xor_sum & (-xor_sum);
        int num1 = 0, num2 = 0;
        for (auto num : nums) {
            if (num & lowbit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution260

using namespace solution260;
int main() {
    std::cout << "Leetcode "
              << "260" << std::endl;
    Solution solution;

    return 0;
}