#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2683 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 相邻值的按位异或
    // 类似累加
    // o[n-1] = o[0] ^ d[0] ^ ... ^ d[n-2]
    // o[0] ^ o[n-1] = d[n-1]
    // d[0] ^ ... d[n-1] = 0
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0;
        for (const int& d : derived) {
            sum ^= d;
        }
        return sum == 0;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2683

using namespace solution2683;
int main() {
    std::cout << "Leetcode "
              << "2683" << std::endl;
    Solution solution;

    return 0;
}