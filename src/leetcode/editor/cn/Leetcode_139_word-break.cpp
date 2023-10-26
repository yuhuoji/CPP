#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution139 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO @date 2023-10-25 难
    // 枚举分割点
    // dp[i] 前i个字符能否被分割
    // dp[i] = dp[j]&&check(s[j..i-1]), 0 <= j <= i
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        auto wordDictSet = unordered_set<string>(wordDict.begin(), wordDict.end());

        vector<bool> dp(n + 1, false); // 0~n
        dp[0] = true;
        function<bool(string)> check = [&](const string& t) -> bool {
            return wordDictSet.find(t) != wordDictSet.end();
        };

        for (int i = 1; i <= n; ++i) { // dp[i] 0~i-1
            for (int j = 0; j < i; ++j) {
                if (dp[j] && check(s.substr(j, i - j))) { //[0..j-1] [j..i-1]
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    // 回溯，TLE
    bool wordBreak1(string s, vector<string>& wordDict) {
        int n = s.length();
        auto wordDictSet = unordered_set<string>();
        for (const auto& word : wordDict) {
            wordDictSet.insert(word);
        }

        bool ans = false;
        vector<string> path;

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans = true;
                return;
            }
            for (int j = i; j < n; ++j) { // [i,j]
                if (wordDictSet.find(s.substr(i, j - i + 1)) != wordDictSet.end()) {
                    dfs(j + 1);
                }
            }
        };

        dfs(0);
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution139

using namespace solution139;
int main() {
    std::cout << "Leetcode "
              << "139" << std::endl;
    Solution solution;

    string s = "leetcode";
    //"acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb";
    vector<string> wordDict = {
        "leet", "code"
        //"abbcbda", "cbdaaa", "b", "dadaaad", "dccbbbc", "dccadd", "ccbdbc", "bbca", "bacbcdd", "a", "bacb", "cbc", "adc", "c", "cbdbcad", "cdbab", "db", "abbcdbd", "bcb", "bbdab", "aa", "bcadb", "bacbcb", "ca", "dbdabdb", "ccd", "acbb", "bdc", "acbccd", "d", "cccdcda", "dcbd", "cbccacd", "ac", "cca", "aaddc", "dccac", "ccdc", "bbbbcda", "ba", "adbcadb", "dca", "abd", "bdbb", "ddadbad", "badb", "ab", "aaaaa", "acba", "abbb"
    };

    cout << solution.wordBreak(s, wordDict) << endl;

    return 0;
}