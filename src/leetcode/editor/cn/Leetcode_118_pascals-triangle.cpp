#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution118 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 前n行
    // 第n行有n个数，只与上一行有关，空间n+n-1
    // 递推 n row' fn = n-1 row's fn-1 + fn
    // 递归
    vector<vector<int>> generate(int numRows) {
        // base case 0
        if (numRows == 1) {
            return vector<vector<int>>{{1}};
        }
        if (numRows == 2) {
            return vector<vector<int>>{{1}, {1, 1}};
        }
        vector<vector<int>> ans = {{1}, {1, 1}};
        for (int i = 2; i < numRows; ++i) {         // i row, 2...numRows-1
            vector<int> row(i+1, 1);                  // 0,n-1
            for (int j = 1; j < i; ++j) { // position j, 1...n-2
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.emplace_back(row);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution118

using namespace solution118;
int main() {
    std::cout << "Leetcode "
              << "118" << std::endl;
    Solution solution = Solution();
    int numRows = 5;
    vector<vector<int>> triangle = solution.generate(numRows);
    for (auto row : triangle) {
        for (auto item : row) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}