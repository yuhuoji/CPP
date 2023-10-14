#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2141 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // 老是int溢出 >_<
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int len = batteries.size();
        long long sum = 0;
        for (auto item : batteries) {
            sum += item;
        }

        //二分初始的范围
        int max_value = *max_element(batteries.begin(), batteries.end());
        long l = 0, r = max_value; // 水均匀填坑
        if (sum >= (long) n * max_value) { //最终结果一定大于max, 都是碎片电池
            r = sum / n;
        }

        // 粗略的范围[l,r]
        long long ans = 0;
        while (l <= r) {
            long m = ((r - l) >> 1) + l;
            if (check(n, batteries, m)) { // 尝试更长的时间
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }

    // 能否让n台电脑运行minute
    bool check(int n, const vector<int>& batteries, long long minute) {
        long long sum = 0; // 碎片电池的和
        for (auto battery : batteries) {
            if (battery >= minute) {
                n--;
            } else {
                sum += battery;
            }
            if (sum >= (long long) n * minute) { // 像水流动填坑一样？
                return true;
            }
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2141

using namespace solution2141;
int main() {
    std::cout << "Leetcode "
              << "2141" << std::endl;
    Solution solution;

    int n = 2;
    vector<int> batteries = {3, 3, 3};
    cout << solution.maxRunTime(n, batteries) << endl;
    return 0;
}