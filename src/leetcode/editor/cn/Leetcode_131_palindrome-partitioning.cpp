#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution131 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-26 dp
    //


    //REVIEW @date 2023-10-26

    //方法2
    vector<vector<string>> partition2(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; ++j) { // 枚举回文串的结束位置[i,j]
                string t = s.substr(i, j - i + 1);
                string reverse_t = t;
                std::reverse(reverse_t.begin(), reverse_t.end());
                if (t == reverse_t) {
                    path.emplace_back(t);
                    dfs(j + 1);
                    path.pop_back(); // 恢复现场
                }
            }
        };

        dfs(0);
        return ans;
    }

    // 选还是不选i后面的逗号分割
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        //[字串起点start, 终点i]
        function<void(int, int)> dfs = [&](int start, int i) -> void {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            // 不选
            if (i < n - 1) {
                dfs(start, i + 1);
            }

            // 选
            string t = s.substr(start, i - start + 1);
            string reverse_t = t;
            std::reverse(reverse_t.begin(), reverse_t.end());
            if (t == reverse_t) { // 是回文
                path.emplace_back(t);
                dfs(i + 1, i + 1);
                path.pop_back();
            }
        };

        dfs(0, 0);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution131

using namespace solution131;
int main() {
    std::cout << "Leetcode "
              << "131" << std::endl;
    Solution solution;

    return 0;
}