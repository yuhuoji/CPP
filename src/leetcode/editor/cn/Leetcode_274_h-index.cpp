#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution274 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // max(论文数量&引用次数)
    // REVIEW @date 2023-10-29

    //二分
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 1, r = n;

        function<bool(int)> check = [&](int k) {
            int cnt = 0;
            for (const auto& i : citations) {
                if (i >= k) {
                    cnt++;
                }
            }
            return cnt >= k;
        };

        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            if (check(m)) {
                l = m + 1; //[m,r)
            } else {
                r = m - 1; //[l,m)
            }
        }
        return r;
    }

    // 二分h, 最小的最大值, [l,r)
    int hIndex3(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n + 1;

        // 判断是否有cnt个数大于等于cnt
        function<bool(int)> check = [&](int k) {
            int cnt = 0;
            for (const auto& i : citations) {
                if (i >= k) {
                    cnt++;
                }
            }
            return cnt >= k;
        };

        //[l,r)
        while (l < r) {
            int m = ((r - l) >> 1) + l;
            if (check(m)) {
                l = m + 1; //[m,r)
            } else {
                r = m; //[l,m)
            }
        }
        return l - 1;
    }

    // 计数排序, 统计当前引用次数的论文有几篇
    int hIndex2(vector<int>& citations) {
        int n = citations.size();
        vector<int> counter(n + 1); // 当前次数的论文数量[0..n-1], 超过n的[n]
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n) {
                counter[n]++;
            } else {
                counter[citations[i]]++;
            }
        }
        int total = 0;
        for (int i = n; i >= 0; --i) {
            total += counter[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }

    // 排序
    int hIndex1(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int t = min(citations[i], n - i);
            ans = max(ans, t);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution274

using namespace solution274;
int main() {
    std::cout << "Leetcode "
              << "274" << std::endl;
    Solution solution;

    vector<int> citations = {0};
    cout << solution.hIndex(citations) << endl;

    return 0;
}