#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution136 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //位运算，出现两次的位置对2取余为0，出现一次的为1
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) { // 0...31位
            int total = 0;
            for (auto num : nums) {
                total += ((num >> i) & 1); // 取第i位二进制数
            }
            if (total % 2) { // 为1
                ans |= (1 << i);
            }
        }
        return ans;
    }
    // 位运算
    // a^a = 0
    // 0^a = a
    // a^b^b = a
    int singleNumber2(vector<int>& nums) {
        int ans = 0;
        for (auto num : nums) {
            ans ^= num;
        }
        return ans;
    }
    //hash
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

} // namespace solution136

using namespace solution136;
int main() {
    std::cout << "Leetcode "
              << "136" << std::endl;
    Solution solution;

    return 0;
}