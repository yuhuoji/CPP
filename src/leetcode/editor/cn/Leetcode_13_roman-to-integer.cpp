#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution13 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

public:
    //正常：小的数字在大的数字的右边。相加
    //小的数字在大的数字左边，相减
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution13

using namespace solution13;
int main() {
    std::cout << "Leetcode " << 13 << std::endl;
    Solution solution = Solution();

    return 0;
}