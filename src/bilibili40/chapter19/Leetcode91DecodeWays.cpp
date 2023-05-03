/**
 * @date 2023-05-03
 * leetcode 91
 */
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class Solution {
private:
    /**
     * 1~26 <-> a~z
     * 从arr的i位置往后解码
     * 递归
     */
    int processRecursive(const char* chars, int index) {
        if (index == strlen(chars)) { // 终止位置，之前的转化成功
            return 1;
        }
        // index后续还有字符
        if (chars[index] == '0') { // 0无法对应
            return 0;
        }
        int res = process(chars, index + 1); //[index]，一位转换
        if (index == strlen(chars) - 1) {    // index后面没有了
            return res;
        }
        if (((chars[index] - '0') * 10 + (chars[index + 1] - '0')) < 27) { // [index][index+1]，两位转化
            res += process(chars, index + 2);
        }
        return res;
    }
    int dpWays(const char* chars, int index) {
        if (index < 1) {
            return 0;
        }

        int dp[N + 1];
    }

public:
    /**
     *
     */
    int numDecodings(string s) {
        const char* chars = s.c_str();
        return processRecursive(chars, 0);
    }
};
int main() {
    string s = "226";
    Solution solution;
    cout << solution.numDecodings(s) << endl;
}