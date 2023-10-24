#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2904 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-24
    //用后缀数组比较字典序

    // 滑动窗口
    // 枚举右端点，移动左端点
    string shortestBeautifulSubstring(string s, int k) {
        if (count(s.begin(), s.end(), '1') < k) {
            return "";
        }
        int n = s.length();
        string ans = s; // s就是最长的答案
        int cnt1 = 0;
        //[l,r]
        for (int right = 0, left = 0; right < n; ++right) { // 枚举右端点
            cnt1 += s[right] == '1' ? 1 : 0;                // cnt1 += s[right] - '0';
            while (cnt1 > k || s[left] == '0') {
                cnt1 -= s[left] - '0';
                left++;
            }
            if (cnt1 == k) {
                string t = s.substr(left, right - left + 1);
                if (t.length() < ans.length() || t.length() == ans.length() && t < ans) {
                    ans = t;
                }
            }
        }
        return ans;
    }

    // 枚举
    string shortestBeautifulSubstring1(string s, int k) {
        if (count(s.begin(), s.end(), '1') < k) {
            return "";
        }
        int n = s.length();
        // cnt>=k, 一定有解
        for (int size = k; size <= n; ++size) { // 枚举size, 首先要最短的
            string ans = "";
            //[i-size, i-1]
            for (int i = size; i <= n; ++i) { // 枚举结束位置
                string ss = s.substr(i - size, size);
                if ((ans == "" || ss < ans) && count(ss.begin(), ss.end(), '1') == k) { // 维护字典序最小
                    ans = ss;
                }
            }
            if (!ans.empty()) { // 当前长度满足条件字典序最小的
                return ans;
            }
        }
        return 0;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2904

using namespace solution2904;
int main() {
    std::cout << "Leetcode "
              << "2904" << std::endl;
    Solution solution;

    return 0;
}