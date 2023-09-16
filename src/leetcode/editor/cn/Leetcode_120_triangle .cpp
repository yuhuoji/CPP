#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution120 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        if (triangle.size() == 1) {
            return triangle[0][0];
        }
        int n = triangle.size();
        for (int i = n - 2; i >= 0; --i) {    // up to down
            for (int j = 0; j < i + 1; ++j) { // left to right
                triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return triangle[0][0];
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
    cout << solution.minimumTotal(triangle) << endl;
    return 0;
}