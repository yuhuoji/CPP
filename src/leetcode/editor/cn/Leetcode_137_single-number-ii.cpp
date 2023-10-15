#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution137 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-15 数字电路???

    // 位运算，每一位都是所有数的%3
    int singleNumber2(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) { // 0...31位
            int total = 0;
            for (auto num : nums) {
                total += ((num >> i) & 1); // 取第i位二进制数
            }
            if (total % 3) { // 为1
                ans |= (1 << i);
            }
        }
        return ans;
    }

    // hash
    int singleNumber1(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        for (auto num : nums) {
            if (mp[num] == 1) {
                return num;
            }
        }
        return -1;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution137

using namespace solution137;
int main() {
    std::cout << "Leetcode "
              << "137" << std::endl;
    Solution solution;

    return 0;
}