#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution10II {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO dp
    //递归
    int numWays(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return (numWays(n - 1) + numWays(n - 2)) % 1000000007;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution10II

using namespace solution10II;
int main() {
    std::cout << "Leetcode "
              << "Sword Offer 10- II" << std::endl;
    Solution solution = Solution();
    int n = 7;
    cout << solution.numWays(n) << endl;
    return 0;
}