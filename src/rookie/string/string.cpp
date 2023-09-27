//
// Created by Legion on 2023/9/27.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
};

int main() {
    Solution solution;
    string string1 = "hello";
    string1.substr(0, 2);
    cout << string1.substr(0, 2) << endl;
    string1.append(" world");
    cout << string1 << endl;
    string1[0] = 'H';
    cout << string1 << endl;

    return 0;
}