#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution475 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //双指针
    //时间复杂度O(n)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); ++i) { // 当前房屋i，当前热水器j
            int curDistance = abs(houses[i] - heaters[j]);
            while (j < heaters.size() - 1 // 热水器保持在最后一个
                   && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                j++;
                curDistance = min(curDistance, abs(houses[i] - heaters[j]));
            }
            ans = max(ans, curDistance);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution475

using namespace solution475;
int main() {
    std::cout << "Leetcode "
              << "475" << std::endl;
    Solution solution;

    return 0;
}