#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution74 {
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 暴力 O(m*n)
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (matrix[r][c] == target) {
                    return true;
                }
            }
        }
        return false;
    }

    // 一次二分O(logm*n)
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int left = 0;
        int right = row * column - 1;
        while (left <= right) {
            int median = (right - left) / 2 + left;
            int r = median / column;
            int c = median % column;
            //(r,c)
            //            if (matrix[r][c] == target) {
            //                return true;
            //            } else if (matrix[r][c] > target) {
            //                right = median - 1;
            //            } else {
            //                left = median + 1;
            //            }
            if (target <= matrix[r][c]) { // 找到第一个>= target的位置, 最后比较是否等于target
                right = median - 1;
            } else {
                left = median + 1;
            }
        }
        int median = (right - left) / 2 + left;
        int r = median / column;
        int c = median % column;
        if (matrix[r][c] == target) {
            return true;
        } else {
            return false;
        }
    }

    // 贪心 O(m*n)
    bool searchMatrix3(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int r = 0;
        int c = column - 1;
        // start from (r,c)
        while (r < row && c >= 0) {
            if (matrix[r][c] < target) {
                r++;
            } else if (matrix[r][c] > target) {
                c--;
            } else if (matrix[r][c] == target) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
    // 两次二分 O(logm * logn)
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        // 二分查找行
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int>& a) {
            return b < a[0];
        });
        // 二分查找列
        if (row == matrix.begin()) {
            return false;
        }
        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution74

using namespace solution74;
int main() {
    std::cout << "Leetcode " << 74 << std::endl;
    Solution solution = Solution();
    //    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> matrix = {{1}};
    int target = 2;
    cout << boolToString(solution.searchMatrix(matrix, target)) << endl;

    return 0;
}