#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution263 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // n = 2^a + 3^b + 5^c
    bool isUgly(int n) {
        if (n <= 1) {
            return false;
        }
        vector<int> factors = {2, 3, 5};
        for (auto factor : factors) {
            while (n % factor == 0) {
                n /= factor;
            }
        }
        return n == 1;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution263

using namespace solution263;
int main() {
    std::cout << "Leetcode "
              << "263" << std::endl;
    Solution solution;

    return 0;
}