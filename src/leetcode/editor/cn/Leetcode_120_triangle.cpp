#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution120 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 从顶到底，滚动数组，两行交替使用
    int minimumTotal3(const vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = triangle[0][0];
        // 交替使用dp[0] dp[1], 用pre填充cur
        for (int i = 1; i < n; ++i) { // 1...n-1
            int cur = i % 2;
            int pre = 1 - cur;
            // cur 1 0 1 0
            // pre 0 1 0 1
            dp[cur][0] = dp[pre][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                dp[cur][j] = min(dp[pre][j - 1], dp[pre][j]) + triangle[i][j];
            }
            dp[cur][i] = dp[pre][i - 1] + triangle[i][i];
        }
        int cur = (n - 1) % 2;
        return *min_element(dp[cur].begin(), dp[cur].end());
    }
    // 从顶到底
    int minimumTotal2(const vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> ans(n, vector<int>(n));     // 空间O(n^2)
        ans[0][0] = triangle[0][0];                     // (0,0)
        for (int i = 1; i < n; ++i) {                   // row i, with i+1 item, i in 1...n-1
            ans[i][0] = ans[i - 1][0] + triangle[i][0]; //(i,0) = (i-1,0)
            for (int j = 1; j < i; ++j) {
                ans[i][j] = min(ans[i - 1][j - 1], ans[i - 1][j]) + triangle[i][j];
            }
            ans[i][i] = ans[i - 1][i - 1] + triangle[i][i]; //(i,i) = (i-1,i-1)
        }
        auto it = min_element(ans[n - 1].begin(), ans[n - 1].end());
        return *it;
    }
    // 从底到顶，修改原数组
    int minimumTotal0(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        if (triangle.size() == 1) {
            return triangle[0][0];
        }
        int n = triangle.size();
        for (int i = n - 2; i >= 0; --i) {    // down to up
            for (int j = 0; j < i + 1; ++j) { // left to right
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
    // 从底到顶，滚动数组
    //空间O(n)
    int minimumTotal(const vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> cur(n);
        vector<int> pre(n + 1);
        for (int i = n - 1; i >= 0; --i) { // down to up
            for (int j = 0; j <= i; ++j) { // left to right
                cur[j] = min(pre[j], pre[j + 1]) + triangle[i][j];
            }
            swap(cur, pre); // 动态规划交换数组
        }
        return pre[0];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution120

using namespace solution120;
int main() {
    std::cout << "Leetcode "
              << "120" << std::endl;
    Solution solution = Solution();
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << solution.minimumTotal2(triangle) << endl;
    cout << solution.minimumTotal3(triangle) << endl;
    cout << solution.minimumTotal(triangle) << endl;
    cout << solution.minimumTotal0(triangle) << endl;
    return 0;
}