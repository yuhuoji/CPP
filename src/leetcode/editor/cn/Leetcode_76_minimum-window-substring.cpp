#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution76 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-24 优化？

    // 窗口内字符>=t, 包含t时cnt>=0
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }
        unordered_map<char, int> cnt; // 原字符串t和滑动窗口的统计次数
        for (const auto& c : t) {
            cnt[c]--;
        }

        // 比较当前滑动窗口是否含有t
        auto check = [&]() {
            for (const auto& p : cnt) {
                if (p.second < 0) {
                    return false;
                }
            }
            return true;
        };

        int min_len = INT_MAX / 2, ans_l = -1;
        // 滑动窗口[l,r]
        for (int right = 0, left = 0; right < s.length(); ++right) { // 枚举右端点
            cnt[s[right]]++;
            while (check()) {                     // 移动左端点
                if (right - left + 1 < min_len) { // 保证只有一个结果
                    min_len = right - left + 1;
                    ans_l = left;
                }
                cnt[s[left]]--;
                left++;
            }
        }

        return ans_l == -1 ? "" : s.substr(ans_l, min_len);
    }

    // 两个hashmap
    string minWindow1(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }
        unordered_map<char, int> target, cnt; // 原字符串t和滑动窗口的统计次数
        for (const auto& c : t) {
            target[c]++;
        }

        // 比较当前滑动窗口是否含有t
        auto check = [&]() {
            for (const auto& p : target) {
                if (cnt[p.first] < p.second) {
                    return false;
                }
            }
            return true;
        };

        int min_len = INT_MAX / 2, ans_l = -1;
        // 滑动窗口[l,r]
        for (int right = 0, left = 0; right < s.length(); ++right) { // 枚举右端点
            cnt[s[right]]++;
            while (check()) {                     // 移动左端点
                if (right - left + 1 < min_len) { // 保证只有一个结果
                    min_len = right - left + 1;
                    ans_l = left;
                }
                cnt[s[left]]--;
                left++;
            }
        }

        return ans_l == -1 ? "" : s.substr(ans_l, min_len);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution76

using namespace solution76;
int main() {
    std::cout << "Leetcode "
              << "76" << std::endl;
    Solution solution;

    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << solution.minWindow(s, t) << endl;

    return 0;
}