/**
 * @date 2023-05-01
 * 完整的括号字符串()
 * 现在有括号字符串s，至少需要几个括号可以补全
 */
#include <iostream>
#include <string>
using namespace std;
class NeedParentheses {
public:
    NeedParentheses(){};
    int needParentheses(string str) {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.find("(", i) == i) { // (
                count++;
            } else {              // )
                if (count == 0) { // 需要加左括号， count--; ans++; count =0;
                    ans++;
                } else {
                    count--;
                }
            }
        }
        return count + ans; // count>=0需要加的左括号，ans需要加的右括号
    }
};

int main() {
    NeedParentheses needParentheses;
    string str = "(()(()(())))(";
    cout << needParentheses.needParentheses(str) << endl;
}