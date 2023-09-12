#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution49 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end()); // sort key
            mp[key].emplace_back(str);
        }
        // map
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution49

using namespace solution49;
int main() {
    std::cout << "Leetcode " << 49 << std::endl;
    Solution solution = Solution();
    //["eat","tea","tan","ate","nat","bat"]
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = solution.groupAnagrams(strs);
        for (auto& v : ans) {
                for (auto& s : v) {
                cout << s << " ";
                }
                cout << endl;
        }

    return 0;
}