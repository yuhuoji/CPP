//
// Created by Legion on 2023/9/24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int count0 = 0;
        int count1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                count0++;
            } else {
                count1++;
            }
        }
        s[n - 1] = '1';
        count1--;
        int i = 0;
        while (count1--) {
            s[i++] = '1';
        }
        while(count0--) {
            s[i++] = '0';
        }
        return s;
    }
};

int main() {
    Solution solution;
    cout << solution.maximumOddBinaryNumber("100101") << endl;
    string s = "0101";

    return 0;
}