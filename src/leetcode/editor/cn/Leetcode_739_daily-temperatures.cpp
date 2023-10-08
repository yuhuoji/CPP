#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution739 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 单调栈，从前向后
    // 没有找到下一个更大的数
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int t = temperatures[i];
            while (!stk.empty() && t > temperatures[stk.top()]) {
                int j = stk.top();
                stk.pop();
                ans[j] = i - j;
            }
            stk.push(i);
        }
        return ans;
    }

    // 单调栈，从后向左
    // 下一个更大的数
    vector<int> dailyTemperatures1(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            int t = temperatures[i];
            while (!stk.empty() && t >= temperatures[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) { // 栈顶元素大于i
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution739

using namespace solution739;
int main() {
    std::cout << "Leetcode "
              << "739" << std::endl;
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    auto ans = solution.dailyTemperatures(temperatures);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}