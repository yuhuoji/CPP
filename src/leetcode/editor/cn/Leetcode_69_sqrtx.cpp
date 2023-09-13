#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution69 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        if (x==0){
            return 0;
        }
        int l = 0;
        int r = x;
        int ans =-1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if ((long long)m*m <= x) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution69

using namespace solution69;
int main() {
    std::cout << "Leetcode " << 69 << std::endl;
    Solution solution = Solution();
    int x = 9;
    cout << solution.mySqrt(x) << endl;
    return 0;
}