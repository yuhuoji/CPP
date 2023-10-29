#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution239 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-29 其他方法

    // 单调栈
    // 单调：值单调递减, 下标单调低价
    // 当值小且下标靠前时, 就不可能为滑动窗口最大值了, 可以永久移除
    // 队首的元素就是当前滑动窗口的最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q; // 存下标, 同一时间至少有1个, 最多为k个元素
        // 初始化
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) { // 不可能为滑动窗口最大值了
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans;
        ans.emplace_back(nums[q.front()]);
        //[i-k+1,i]
        for (int i = k; i < n; ++i) {
            // 后边进
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            // 前面出
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }

    // 优先队列
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) { // 初始化
            q.emplace(nums[i], i);
        }
        vector<int> ans;
        ans.emplace_back(q.top().first);
        // [i-k+1,i]
        for (int i = k; i < n; ++i) { // 枚举右端点
            q.emplace(nums[i], i);
            while (q.top().second < i - k + 1) { // 在窗口外
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution239

using namespace solution239;
int main() {
    std::cout << "Leetcode "
              << "239" << std::endl;
    Solution solution;

    return 0;
}