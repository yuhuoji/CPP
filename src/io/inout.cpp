//
// Created by yuhuoji on 2023/10/27.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
};

int main() {
    Solution solution;
    // 读入一个数组
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "nums: ";
    // 输出
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}