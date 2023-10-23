#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution1720 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> arr(n + 1);
        arr[0] = first;
        for (int i = 1; i < n + 1; ++i) {
            arr[i] = encoded[i - 1] ^ arr[i - 1];
        }
        return arr;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution1720

using namespace solution1720;
int main() {
    std::cout << "Leetcode "
              << "1720" << std::endl;
    Solution solution;

    return 0;
}