#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2433 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //sum ^ arr[i] = pref[i]
    //sum ^ sum ^ arr[i] = pref[i] ^ sum
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        int sum = 0; //异或和
        for (int i = 0; i < n; ++i) {
            ans[i] = pref[i] ^ sum;
            sum ^= ans[i];
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2433

using namespace solution2433;
int main() {
    std::cout << "Leetcode "
              << "2433" << std::endl;
    Solution solution;

    return 0;
}