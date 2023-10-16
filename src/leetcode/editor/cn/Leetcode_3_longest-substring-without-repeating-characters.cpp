#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution3 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 滑动窗口
    // 枚举左端点
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ust;
        int n = s.size();
        int ans = 1;
        for (int l = 0, r = 0; r < n; ++r) {
            ust[s[r]] += 1;
            while (ust[s[r]] > 1) {
                ust[s[l]] -= 1;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution3

using namespace solution3;
int main() {
    std::cout << "Leetcode "
              << "3" << std::endl;
    Solution solution;

    return 0;
}