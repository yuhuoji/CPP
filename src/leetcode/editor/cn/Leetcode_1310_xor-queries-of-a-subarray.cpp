#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1310 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 子数组异或和
    // 前缀和
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n + 1); // 偏移一位, 方便处理l=0，n+1位, [0, i-1]的异或和
        pre[0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }

        int len = queries.size();
        vector<int> ans(len);
        for (int i = 0; i < len; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            // xor[l, r] = xor[0, r] ^ xor[0, l-1]
            ans[i] = pre[r + 1] ^ pre[l];
        }

        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution1310

using namespace solution1310;
int main() {
    std::cout << "Leetcode "
              << "1310" << std::endl;
    Solution solution;

    return 0;
}