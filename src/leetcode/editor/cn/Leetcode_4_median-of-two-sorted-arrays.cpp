#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution4 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // log 二分查找
    // REVIEW @date 2023-10-21
    // 求中位数转换成求第 k 小的数，可以避免奇偶数讨论
    // 二分, 比较a[k/2-1]和b[k/2-1], 每次排除k/2个元素
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_len = nums1.size() + nums2.size();

        // 找第k小的元素
        auto getKthNum = [&nums1, &nums2](int k) {
            int m = nums1.size();
            int n = nums2.size();

            int index1 = 0, index2 = 0;
            // num1[index1,m-1]
            // num2[index2,n-1]
            while (true) {
                // base case
                if (index1 >= m) {
                    return nums2[index2 + k - 1];
                }
                if (index2 >= n) {
                    return nums1[index1 + k - 1];
                }
                if (k == 1) { // 找第一小的元素
                    return min(nums1[index1], nums2[index2]);
                }

                int newIndex1 = min(index1 + k / 2 - 1, m - 1); // 防止溢出
                int newIndex2 = min(index2 + k / 2 - 1, n - 1);
                int pivot1 = nums1[newIndex1];
                int pivot2 = nums2[newIndex2];
                if (pivot1 <= pivot2) {
                    k -= newIndex1 - index1 + 1; // 迭代k
                    index1 = newIndex1 + 1;      // 排除index1~newIndex1之间的元素
                } else {
                    k -= newIndex2 - index2 + 1;
                    index2 = newIndex2 + 1;
                }
            }
        };

        if (total_len % 2 == 1) {
            return getKthNum((total_len + 1) / 2);
        } else {
            return (double) (getKthNum(total_len / 2) + getKthNum(total_len / 2 + 1)) / 2.0; // double
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution4

using namespace solution4;
int main() {
    std::cout << "Leetcode "
              << "4" << std::endl;
    Solution solution;

    return 0;
}