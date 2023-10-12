#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution875 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 二分答案法
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = 0;
        for (auto pile : piles) {
            high = max(high, pile);
        }
        //[low,high]上二分
        int ans = 0;
        while (low <= high) {
            int m = (high - low) / 2 + low;
            if (getTime(piles, m) <= h) { //当前速度满足，实际需要的速度可能更小
                ans = m;
                high = m - 1;
            } else {
                low = m + 1;
            }
        }
        return ans; //low
    }

    // speed增加，time减少
    int getTime(const vector<int>& piles, int speed) {
        int ans = 0;
        for (auto pile : piles) {
            int time = (pile + speed - 1) / speed; // a/b向上取整 = (a+b-1)/b
            //pile % speed == 0 ? pile / speed : pile / speed + 1;
            ans += time;
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution875

using namespace solution875;
int main() {
    std::cout << "Leetcode "
              << "875" << std::endl;
    Solution solution;

    return 0;
}