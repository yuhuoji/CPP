#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution22 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-10-29
    // 选或不选
    
//        vector<string> generateParenthesis(int n) {
//            vector<string> ans;
//            string path;
//
//            //当前排i位置, (数量是left
//            //)数量是i-left
//            function<void(int, int)> dfs = [&](int i, int left) {
//                if (i==2*n){
//                    ans.push_back(path);
//                    return ;
//                }
//                if ()
//            };
//
//            dfs(0,0);
//            return ans;
//        }

    vector<string> generateParenthesis1(int n) {
        vector<string> ans;
        string path;

        // 从左向右，每个位置的左侧left>=right
        function<void(int, int)> dfs = [&](int left, int right) {
            if (left == 0 && right == 0) {
                ans.push_back(path);
                return;
            }
            if (left > 0) {
                path.push_back('(');
                dfs(left - 1, right);
                path.pop_back();
            }
            if (left < right) { // 剩余的left=right，则只能用(，left<right能用)
                path.push_back(')');
                dfs(left, right - 1);
                path.pop_back();
            }
        };

        dfs(n, n); //n对括号
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution22

using namespace solution22;
int main() {
    std::cout << "Leetcode "
              << "22" << std::endl;
    Solution solution;

    return 0;
}