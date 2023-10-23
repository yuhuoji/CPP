#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution54 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m * n);
        int u = 0, d = m - 1, l = 0, r = n - 1;
        // 上下边界 u <= i <= d
        // 左右边界 l <= j <= r
        int k = 0;
        while (true) {
            // 上 下 左 右
            // u行
            for (int j = l; j <= r; ++j) {
                ans[k++] = matrix[u][j];
            }
            if (++u > d) {
                break;
            }
            // r列
            for (int i = u; i <= d; ++i) {
                ans[k++] = matrix[i][r];
            }
            if (l > --r) {
                break;
            }
            // d行
            for (int j = r; j >= l; --j) {
                ans[k++] = matrix[d][j];
            }
            if (u > --d) {
                break;
            }
            // l列
            for (int i = d; i >= u; --i) {
                ans[k++] = matrix[i][l];
            }
            if (++l > r) {
                break;
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution54

using namespace solution54;
int main() {
    std::cout << "Leetcode "
              << "54" << std::endl;
    Solution solution;
    vector<vector<int>> matrix = {{1}};
    vector<int> ans = solution.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}