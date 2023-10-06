#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution881 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-06
    // 扩展：再增加一个要求,如果两人一船那么体重之和必须是偶数,又该怎么做? (大厂真考过)
    int numRescueBoats(vector<int>& people, int limit) {
        return 0;
    }

    // 双指针
    int numRescueBoats1(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int count = 0;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int sum = l == r ? people[l] : people[l] + people[r]; // 只剩一个人
            if (sum > limit) {                                    // 让r一个人一艘船
                r--;
            } else { // 让 l 和 r 一艘船
                r--;
                l++;
            }
            count++;
        }
        return count;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution881

using namespace solution881;
int main() {
    std::cout << "Leetcode "
              << "881" << std::endl;
    Solution solution;

    return 0;
}