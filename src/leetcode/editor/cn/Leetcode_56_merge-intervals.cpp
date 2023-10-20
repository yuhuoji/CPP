#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution56 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // 排序, 合并
        sort(intervals.begin(), intervals.end()); // 默认按字典序排
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            int l = intervals[i][0], r = intervals[i][1];
            if (ans.size() == 0 || ans.back()[1] < l) { // 不重叠
                ans.push_back({l, r});
            } else { //>=
                ans.back()[1] = max(ans.back()[1], r);
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution56

using namespace solution56;
int main() {
    std::cout << "Leetcode "
              << "56" << std::endl;
    Solution solution;

    return 0;
}