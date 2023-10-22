//
// Created by yuhuoji on 2023/9/24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // TODO @date 2023-9-24
    // 贪心？
    // 单调递减
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            long long height = 0;
            int curHeight = maxHeights[i]; // 当前为顶
            if (i == 0 && maxHeights[0] >= maxHeights[1]) {
                int pos = 1;
                height += maxHeights[0];
                while (pos <= n - 1) {
                    curHeight = min(curHeight, maxHeights[pos]);
                    height += curHeight;
                    pos++;
                }
            } else if (i == n - 1 && maxHeights[n - 2] <= maxHeights[n - 1]) {
                int pos = n - 2;
                height += maxHeights[n - 1];
                while (pos >= 0) {
                    curHeight = min(curHeight, maxHeights[pos]);
                    height += curHeight;
                    pos--;
                }
            } else if (maxHeights[i] >= maxHeights[i - 1] && maxHeights[i] >= maxHeights[i + 1]) {
                int pos = i;
                height = 0;
                curHeight = maxHeights[i];
                while (pos >= 0) {
                    curHeight = min(curHeight, maxHeights[pos]);
                    height += curHeight;
                    pos--;
                }
                pos = i;
                curHeight = maxHeights[i];
                height -= curHeight;
                while (pos <= n - 1) {
                    curHeight = min(curHeight, maxHeights[pos]);
                    height += curHeight;
                    pos++;
                }
            }
            ans = max(ans, height);
        }
        return ans;
    }

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

    vector<int> maxHeights = {6, 5, 3, 9, 2, 7};
    cout << solution.maximumSumOfHeights(maxHeights) << endl;


    return 0;
}