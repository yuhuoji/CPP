#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution275 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 有序数组，升序数组，二分
    // REVIEW @date 2023-10-30

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 1, r = n; //0一定为ture

        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            if (citations[n - m] >= m) {
                l = m + 1; //[m+1,r]
            } else {
                r = m - 1; //[l,m-1]
            }
        }
        return r;
    }

    int hIndex3(vector<int>& citations) {
        int n = citations.size();
        int l = 1, r = n + 1;

        // 左闭右开[l,r)
        while (l < r) {
            // 循环不变量：
            // left-1 的回答一定为「是」
            // right 的回答一定为「否
            int m = ((r - l) >> 1) + l;  // 保证 mid 在二分区间内
            if (citations[n - m] >= m) { // l=0越界
                l = m + 1;               //[m+1,r)
            } else {
                r = m; //[l,m)
            }
        }
        return l - 1;
    }

    int hIndex2(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n;

        //(l,r]
        while (l < r) {
            // 循环不变量：
            // left 的回答一定为「是」
            // right+1 的回答一定为「否
            int m = ((r - l + 1) >> 1) + l; // 保证 mid 在二分区间内
            if (citations[n - m] >= m) {    // l=0越界
                l = m;                      //(m,r]
            } else {
                r = m - 1; //[l,m-1]
            }
        }
        return l; // r
    }

    int hIndex1(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n;

        //[l,r]
        while (l <= r) {
            int m = ((r - l + 1) >> 1) + l; // 防止l = m死循环
            if (citations[n - m] >= m) {
                l = m + 1; //[m,r] -> [m+1,r]
            } else {
                r = m - 1; //[l,m-1]
            }
        }
        return r;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution275

using namespace solution275;
int main() {
    std::cout << "Leetcode "
              << "275" << std::endl;
    Solution solution;

    return 0;
}