/**
 * @date 2023-05-03
 *
 */
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class ParenthesesDeep {
public:
    ParenthesesDeep(/* args */);
    ~ParenthesesDeep();
    static int maxLength(string s) {
        if (s.empty()) { // empty string
            return 0;
        }
        const char* str = s.c_str(); // 原来的字符串
        vector<int> dp(sizeof(str) / sizeof(str[0]), 0);
        int pre = 0;
        int res = 0;
        for (int i = 1; i < strlen(str); i++) {
            if (str[i] == ')') {                         //'('一定为0
                pre = i - dp[i - 1] - 1;                 // 查找与str[i]配对的左括号的位置
                if (pre >= 0 && str[pre] == '(') {       // 不越界，是左括号
                    dp[i] = dp[i - 1] + 2 +              // 至少为dp[i-1]+2
                            (pre > 0 ? dp[pre - 1] : 0); // pre前有pre-1则加上一段
                }
            }
            res = max(res, dp[i]); // 最大值
        }
        return res;
    }
};

ParenthesesDeep::ParenthesesDeep() {}

ParenthesesDeep::~ParenthesesDeep() {}

int main() {
    string str = "(((())";
    cout << ParenthesesDeep::maxLength(str) << endl;
}