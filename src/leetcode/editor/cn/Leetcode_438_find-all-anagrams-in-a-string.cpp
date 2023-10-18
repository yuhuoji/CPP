#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution438 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (n < m) {
            return {};
        }
        // n>m
        vector<int> ans;
        vector<int> s_count(26);
        vector<int> p_count(26);
        for (int i = 0; i < m; ++i) {
            s_count[s[i] - 'a']++;
            p_count[p[i] - 'a']++; // 初始化
        }
        if (s_count == p_count) {
            ans.emplace_back(0);
        }
        //[l,r], r-l+1 = plen
        // s[0...m-1]
        // s[m,n-1]
        for (int i = m; i < n; ++i) {
            // 当前i，前一个i-m
            s_count[s[i] - 'a']++;
            s_count[s[i - m] - 'a']--;
            if (s_count == p_count) {
                ans.emplace_back(i - m + 1); // 插入首位
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution438

using namespace solution438;
int main() {
    std::cout << "Leetcode "
              << "438" << std::endl;
    Solution solution;

    return 0;
}