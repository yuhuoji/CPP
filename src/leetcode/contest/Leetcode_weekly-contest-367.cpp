//
// Created by Legion on 2023/10/15.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 8026. 构造乘积矩阵
    // 暴力？应该会爆
    // 总的product，每一次都取余12345
    // 最多俩0
    // TODO @date 2023-10-15
    // 前后缀分解 238
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); // n行m列
        int cnt = 0;            // 0的个数
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] %= 12345;
                if (grid[i][j] == 0) {
                    cnt++;
                }
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        if (cnt >= 2) { // 大于等于俩0
            return ans;
        }
        if (cnt == 1) { // 一个0
            int r, c;
            long product = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 0) {
                        r = i, c = j;
                    } else {
                        product = product * grid[i][j] % 12345;
                    }
                }
            }
            ans[r][c] = product;
            return ans;
        }
        // 没有0
        long product = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                product = (product * grid[i][j]) % (long) (pow(12345, 2));
            }
        }
        int pre = 1, cur;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cur = grid[i][j];
                product /= cur;
                product *= pre;
                ans[i][j] = product % 12345;
            }
        }
        return ans;
    }

    // 100101. 找出满足差值条件的下标 II
    // 排序+直接找最大的O(n * log n)
    vector<int> findIndices2(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        if (indexDifference >= n) {
            return {-1, -1};
        }

        std::unordered_multimap<int, int> valueToIndices;
        for (int i = 0; i < nums.size(); i++) {
            valueToIndices.emplace(nums[i], i);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
        }
        return {-1, -1};
    }

    // 100084. 最短且字典序最小的美丽子字符串
    // 字典序 <
    // 滑动窗口
    // TODO @date 2023-10-15
    string shortestBeautifulSubstring(string s, int k) {
        return "";
    }
    // 枚举
    string shortestBeautifulSubstring1(string s, int k) {
        if (count(s.begin(), s.end(), '1') < k) {
            return "";
        }
        // 一定有解
        int n = s.size();
        for (int size = k;; ++size) { // 枚举size
            string ans = "";
            //i:0...n-size
            //0..size, n-size..n-1
            for (int i = 0; i + size <= n; ++i) { // 枚举所有长度为size的子串
                string ss = s.substr(i, size);
                if (count(ss.begin(), ss.end(), '1') == k && (ans == "" || ss < ans)) {
                    ans = ss;
                }
            }
            if (!ans.empty()) {
                return ans;
            }
        }
    }

    // 100096. 找出满足差值条件的下标 I
    // 股票
    // indexDifference...n-1枚举j, 维护最大值和最小值
    // 如果有 mx-nums[j] >= valueDifference 或 nums[j]-mn <= valueDifference 就返回
    vector<int> findIndices12(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        if (indexDifference >= n) {
            return {-1, -1};
        }
        // 枚举，维护0...i范围的max和min
        int mx = 0;
        int mn = 0;
        for (int j = indexDifference; j < n; ++j) {
            int i = j - indexDifference;
            if (nums[i] > nums[mx]) {
                mx = i;
            } else if (nums[i] < nums[mn]) {
                mn = i;
            }

            if (nums[mx] - nums[j] >= valueDifference) {
                return {mx, j};
            } else if (nums[j] - nums[mn] >= valueDifference) {
                return {mn, j};
            }
        }
        return {-1, -1};
    }
    // 暴力O(n^2)
    vector<int> findIndices11(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        if (indexDifference >= n) {
            return {-1, -1};
        }
        for (int i = 0; i < n - indexDifference; ++i) {
            for (int j = i + indexDifference; j < n; ++j) {
                if (abs(nums[i] - nums[j]) >= valueDifference) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution solution;
    // nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
    //    vector<int> nums = {2, 7, 0};
    //    int indexDifference = 0;
    //    int valueDifference = 4;

    //    vector<int> ans = solution.findIndices(nums, indexDifference, valueDifference);
    //    cout << ans[0] << " " << ans[1] << endl;
    //

    //

    //    输入：[[3,2,5],[6,4,3],[6,3,1]]
    //        输出：[[615,922,369],[307,461,615],[307,615,1845]]
    //        预期：[[615,7095,7776],[6480,9720,615],[6480,615,1845]]
    //    vector<vector<int>> grid = {{10, 20},
    //                                {18, 16},
    //                                {17, 14},
    //                                {16, 9},
    //                                {14, 6},
    //                                {16, 5},
    //                                {14, 8},
    //                                {20, 13},
    //                                {16, 10},
    //                                {14, 17}};
    // 输入：
    //[[4,8,8],[6,2,5],[7,3,7],[6,3,5]]
    // 输出：
    //[[438,6391,6391],[292,877,2820],[250,585,250],[292,585,2820]]
    // 预期：
    //[[3525,7935,7935],[6465,7050,2820],[7305,585,7305],[6465,585,2820]]
    //    vector<vector<int>> grid = {{4, 8, 8},
    //                                {6, 2, 5},
    //                                {7, 3, 7},
    //                                {6, 3, 5}};
    //
    //    vector<vector<int>> ans = solution.constructProductMatrix(grid);
    //    for (auto& row : ans) {
    //        for (auto& col : row) {
    //            cout << col << " ";
    //        }
    //        cout << endl;
    //    }

    string s = "123456";
    int n = s.size();
    int size = 2;
    cout << s.substr(5, 1) << endl;
    return 0;
}