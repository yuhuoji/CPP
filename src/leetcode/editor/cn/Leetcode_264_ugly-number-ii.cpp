#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution264 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // n = 2^a + 3^b + 5^c
    // 优先队列求第k大的数
    // 一边加一边取，保证
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> factors = {2, 3, 5};
        unordered_set<long> ust;
        priority_queue<long, vector<long>, greater<long>> heap;
        ust.insert(1l);
        heap.push(1l);
        long ugly = 1;
        for (int i = 0; i < n; ++i) { // 第n个ugly
            long cur = heap.top();
            heap.pop();
            ugly = cur;
            for (auto factor : factors) {
                long next = cur * factor;
                if (!ust.count(next)) {
                    ust.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution264

using namespace solution264;
int main() {
    std::cout << "Leetcode "
              << "264" << std::endl;
    Solution solution;

    return 0;
}