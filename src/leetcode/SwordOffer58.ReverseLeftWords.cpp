/**
 * @date 2023-05-06
 * 剑指 Offer 58 - II. 左旋转字符串 LCOF
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
private:
    // start i end
    static void reverseString(string& s, int start, int end) {
        for (int i = start; i <= start + (end - start) / 2; i++) {
            char temp = s[i];
            s[i] = s[start + end - i];
            s[start + end - i] = temp;
        }
    }

public:
    Solution(/* args */) {}
    ~Solution() {}
    /**
     * abcdefg
     * gfdecba
     * cdefgba
     * cdefgab
     */
    static string reverseLeftWords(string s, int n) {
        int length = s.length();

        reverseString(s, 0, length - 1);
        reverseString(s, 0, length - n - 1); // length - n, n
        reverseString(s, length - n, length - 1);
        return s;
    }
};
int main() {
    string s = "abcdefg";
    int k = 2;
    cout << s << ", ";
    cout << Solution::reverseLeftWords(s,k) << endl;
}