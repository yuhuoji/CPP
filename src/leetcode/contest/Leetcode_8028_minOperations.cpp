//
// Created by Legion on 2023/10/8.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //TODO @date 2023-10-08
    int minOperations(string s1, string s2, int x) {
        string diff = "";
        int count = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                diff += '0';
            } else {
                diff += '1';
                count++;
            }
        }
        if (count % 2) {
            return -1;
        }

        int ans=0;


    }
};

int main() {
    Solution solution;
    string s1 = "10110";
    string s2 = "00011";
    int x = 2;
    cout << solution.minOperations(s1, s2, x) << endl;

    //    string result = "";
    //    for (int i = 0; i < s1.size(); ++i) {
    //        if (s1[i] == s2[i]) {
    //            result += '0';
    //        } else {
    //            result += '1';
    //        }
    //    }
    //    cout << result << endl;

    return 0;
}