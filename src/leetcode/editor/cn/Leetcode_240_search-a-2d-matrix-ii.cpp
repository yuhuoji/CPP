#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution240 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-25
    // 贪心O(m+n) z字
    // 二分
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution240

using namespace solution240;
int main() {
    std::cout << "Leetcode "
              << "240" << std::endl;
    Solution solution;

    return 0;
}