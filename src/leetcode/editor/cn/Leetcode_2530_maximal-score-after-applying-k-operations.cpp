#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2530 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 为了避免浮点数运算，我们可以用 ceil{a/b} = (a+b-1)/b
    // 下取整（向下取整）：floor(a/b) = a/b。这将 a 除以 b，然后将结果向下取整。
    // 四舍五入：round(a/b) = (a + b/2) / b。这将 a 除以 b，然后将结果四舍五入到最接近的整数。
    // 反向取整：floor(-a/b) = -ceil(a/b)。这用于处理负数情况下的下取整。

    //原地建堆
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k; ++i) {
            pop_heap(nums.begin(), nums.end());
            ans += nums.back();
            nums.back() = (nums.back() + 2) / 3;
            push_heap(nums.begin(), nums.end());
        }
        return ans;
    }

    //优先队列
    long long maxKelements1(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; ++i) {
            int cur = pq.top();
            pq.pop();
            ans += cur;
            pq.push((cur + 2) / 3); // 用 (x+2)/3 等价 ceil{x/3} 避免浮点数计算
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2530

using namespace solution2530;
int main() {
    std::cout << "Leetcode "
              << "2530" << std::endl;
    Solution solution;

    int a = 10;
    int b = 3;
    cout << (a + b / 2) / b;
    return 0;
}