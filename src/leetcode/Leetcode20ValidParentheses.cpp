/**
 * @date 2023-05-05
 * 20. Valid Parentheses
 */
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    /**
     * 遍历
     */
    static bool isValid1(string s) {
        int length = s.size();
        if (length % 2 == 1) { // 奇数，一定无效
            return false;
        }
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}};
        stack<int> stack;
        for (char& c : s) {       // 遍历
            if (pairs.count(c)) { // 存在 -> 1 -> )]}
                if (stack.empty() || stack.top() != pairs[c]) {
                    return false;
                }
                stack.pop();
            } else { // 不存在 -> 0 -> ([{
                stack.push(c);
            }
        }
        return stack.empty();
    }
    /**
     * 计数
     */
    static bool isValid2(string s) {
        // {')', '('}, count1
        // {']', '['}, count2
        // {'}', '{'}, count3
        int count1 = 0, count2 = 0, count3 = 0;
        for (char& c : s) {
            if (c == '(') {
                ++count1;
            }
            if (c == '[') {
                ++count2;
            }
            if (c == '{') {
                ++count3;
            }
            //)]}
            if (c == ')') {
                --count1;
            }
            if (c == ']') {
                --count2;
            }
            if (c == '}') {
                --count3;
            }
            if (count1 < 0 || count2 < 0 || count3 < 0) {
                return false;
            }
        }
        if (count1 != 0 || count2 != 0 || count3 != 0) {
            return false;
        }
        return true;
    }
};
int main() {
    string s1 = "()[]{}";
    string s2 = "[([)]]"; //c2++,c1++,c2++,c1--,c2--,c2--

    cout << Solution::isValid1(s1) << endl;
    cout << Solution::isValid2(s2) << endl;
}