#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (target == nums[i] + nums[j]) {
                    return {i, j};
                }
            }
        }
        return {};
    }
    vector<int> twoSum(vector<int>& nums, const int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution1

using namespace solution1;
int main() {
    std::cout << "Leetcode " << 1 << std::endl;
    Solution solution = Solution();
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> res = solution.twoSum(nums, target);
    for (int & re : res) {
        cout << re << endl;
    }
//    for (auto it = res.begin(); it != res.end(); ++it) {
//        cout << *it << endl;
//    }
    return 0;
}