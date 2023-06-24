/**
 * 子数组或子串 -> 考虑以每个位置结尾会怎么样
 *
 * 在一个字符串中找到没有重复字符子串中最长的长度。
 * 例如：
 * abcabcbb没有重复字符的最长子串是abc,长度为3
 * bbbbb，答案是b，长度为1
 * pwwkew,答案是wke,长度是3
 * 要求:答案必须是子串, "pwke"是一个子字符序列但不是一个子字符串。
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
class Solution {
private:
public:
    static int maxUnique(const string& str) {
        if (str.empty()) {
            return 0;
        }
        char chars[str.length() + 1];
        std::copy(str.begin(), str.end(), chars);
        chars[str.length()] = '\0'; // 添加结尾的空字符
        int map[256];               // 代替哈希表，字符的ASCII从0~255
        for (int i = 0; i < 256; i++) {
            map[i] = -1;
        }
        int len = 0;
        int pre = -1;
        int cur = 0;

        for (int i = 0; i < strlen(chars); i++) {
            // pre 前一个字符往前推停止的位置
            // map[chars[i]] 字符上一次出现的位置
            pre = std::max(pre, map[chars[i]]);
            cur = i - pre;     // 当前字符长度
            len = std::max(len, cur);
            map[chars[i]] = i; // 当前字符出现在i位置
        }

        return len;
    }
};
int main() {
    cout << "111" << endl;
}