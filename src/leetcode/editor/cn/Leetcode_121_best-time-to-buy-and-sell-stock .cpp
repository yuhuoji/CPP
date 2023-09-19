#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution121 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //贪心
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        for (int price : prices) {
            minPrice = min(minPrice,price);
            maxProfit = max(maxProfit,price-minPrice);
        }
        return maxProfit;
    }
    //暴力
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans,prices[j]-prices[i]);
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution121

using namespace solution121;
int main() {
    std::cout << "Leetcode "
              << "121" << std::endl;
    Solution solution = Solution();
        vector<int> prices = {7,1,5,3,6,4};
        cout << solution.maxProfit1(prices) << endl;
        cout << solution.maxProfit(prices) << endl;

    return 0;
}