#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2525 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        int max_d = max(max(length, width), height);
        long long volume = 1ll * length * width * height;
        bool is_bulky = max_d >= pow(10, 4) || volume >= pow(10, 9), is_heavy = mass >= 100;
        if (is_bulky && is_heavy) {
            return "Both";
        } else if (is_bulky) {
            return "Bulky";
        } else if (is_heavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2525

using namespace solution2525;
int main() {
    std::cout << "Leetcode "
              << "2525" << std::endl;
    Solution solution;
    cout << sizeof(int) << endl; //4
    cout << sizeof(long) << endl;//4
    cout << sizeof(long long) << endl;//8
    return 0;
}