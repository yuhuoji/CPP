#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2895 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        //逆向排序
        sort(tasks.begin(), tasks.end(), greater<int>()); // sort(tasks.rbegin(),tasks.rend());
        int ans = 0;
        for (int i = 0; i < processorTime.size(); ++i) {
            ans = max(ans, processorTime[i] + tasks[4 * i]);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2895

using namespace solution2895;
int main() {
    std::cout << "Leetcode "
              << "2895" << std::endl;
    Solution solution;

    return 0;
}