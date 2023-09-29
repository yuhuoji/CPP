//
// Created by Legion on 2023/9/24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
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
};

int main() {
    Solution solution;
    vector<int> maxHeights = {6,5,3,9,2,7};
    cout << solution.maximumSumOfHeights(maxHeights) << endl;

    return 0;
}