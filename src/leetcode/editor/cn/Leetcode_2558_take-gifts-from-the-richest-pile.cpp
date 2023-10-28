#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2558 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // REVIEW @date 2023-10-28
    //  最大堆
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end()); // 原地堆化heapify（默认最大堆）
        while (k > 0 && gifts[0] > 1) {
            pop_heap(gifts.begin(), gifts.end()); // 将堆顶并移到末尾
            gifts.back() = sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end()); // 把最后一个元素插入堆中
            k--;
        }
        return accumulate(gifts.begin(), gifts.end(), 0ll); //求和
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2558

using namespace solution2558;
int main() {
    std::cout << "Leetcode "
              << "2558" << std::endl;
    Solution solution;

    return 0;
}