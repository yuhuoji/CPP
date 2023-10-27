#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution216 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // REVIEW @date 2023-10-27

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path; // <=k

        // 从[1..i]中选数, 和为sum
        function<void(int, int)> dfs = [&](int i, int sum) {
            int d = k - path.size();
            if (sum < 0 || sum > (i * 2 - d + 1) * d / 2) { // 剩下d个数全选最大的也到不了sum
                return;
            }
            if (i<d){
                return;
            }
            if (path.size() == k) { // 边界条件
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j >= 1; --j) { // 枚举[1..i]
                path.push_back(j);
                dfs(j - 1, sum - j);
                path.pop_back();
            }
        };

        dfs(9, n); //[1..9],sum
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution216

using namespace solution216;
int main() {
    std::cout << "Leetcode "
              << "216" << std::endl;
    Solution solution;

    return 0;
}