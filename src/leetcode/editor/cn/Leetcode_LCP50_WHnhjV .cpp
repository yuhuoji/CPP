#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solutionLCP_50 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        int n = operations.size();
        for (int i = 0; i < n; ++i) {
            int from = operations[i][0];
            int to = operations[i][1];
            int g = gem[from] / 2;
            gem[from] -= g;
            gem[to] += g;
        }
        //        auto maxIt = max_element(gem.begin(), gem.end());
        //        auto minIt = min_element(gem.begin(), gem.end());
        auto [minIt, maxIt] = minmax_element(gem.begin(), gem.end());

        return *maxIt - *minIt;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solutionLCP_50

using namespace solutionLCP_50;
int main() {
    std::cout << "Leetcode "
              << "LCP 50" << std::endl;
    Solution solution = Solution();
    vector<int> gem = {1, 2, 3};
    vector<vector<int>> operations = {{1, 2}, {2, 3}};
    cout << solution.giveGem(gem, operations) << endl;

    return 0;
}