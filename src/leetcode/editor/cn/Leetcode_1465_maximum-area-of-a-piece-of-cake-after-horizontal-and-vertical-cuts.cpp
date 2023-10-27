#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1465 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int height = max(horizontalCuts[0], h - horizontalCuts.back());
        for (int i = 0; i < horizontalCuts.size() - 1; ++i) {
            height = max(height, horizontalCuts[i + 1] - horizontalCuts[i]);
        }

        int width = max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 0; i < verticalCuts.size() - 1; ++i) {
            width = max(width, verticalCuts[i + 1] - verticalCuts[i]);
        }

        return (long long) width * height % MOD;
    }
    const static int MOD = 1'000'000'007;
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution1465

using namespace solution1465;
int main() {
    std::cout << "Leetcode "
              << "1465" << std::endl;
    Solution solution;

    int h = 1000000000;
    int w = 1000000000;
    vector<int> horizontalCuts = {2};
    vector<int> verticalCuts = {2};
    cout << solution.maxArea(h, w, horizontalCuts, verticalCuts) << endl;
    //    5184 81
    return 0;
}