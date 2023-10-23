#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2678 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        // 12 13
        for (string& s : details) {
            // string to int
            ans += stoi(s.substr(11, 2)) > 60 ? 1 : 0;
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2678

using namespace solution2678;
int main() {
    std::cout << "Leetcode "
              << "2678" << std::endl;
    Solution solution;

    int i = 65;                    // ASCII value for 'A'
    char c_1 = static_cast<char>(i); // Converts 65 to 'A'
    cout << "c:" << c_1 << endl;

    char a = 'A';
    string str_1(1, a);
    cout << str_1 << endl;
    string str_2 = string(1, a);
    cout << str_2 << endl;

    return 0;
}