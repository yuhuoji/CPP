#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution17 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const vector<string> MAPPING = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0) {
            return {};
        }
        vector<string> ans;
        vector<string> path(n); // 路径

        // 0~n-1, 枚举第i个字符
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(std::accumulate(path.begin(), path.end(), std::string("")));//std::accumulate
                return;
            }
            for (const auto& c : MAPPING[digits[i] - '0']) { // 枚举第i个字符，digits[i] - '0'转换为int
                path[i] = c;
                dfs(i + 1); // 递归i+1
            }
        };

        dfs(0);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution17

using namespace solution17;
int main() {
    std::cout << "Leetcode "
              << "17" << std::endl;
    Solution solution;

    //std::accumulate

    string digits = "23";
    vector<string> ans = solution.letterCombinations(digits);
    for (const auto& s : ans) {
        cout << s << endl;
    }

    cout<< typeid(digits[0]).name() <<endl;
    cout<< typeid(digits[0] - '0').name() <<endl;
    return 0;
}