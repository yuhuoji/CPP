//
// Created by yuhuoji on 2023/10/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //TODO @date 2023-10-22

    // 枚举
    // 前后缀分解?
    // 记录左侧小于nums[i]的最大值, 怎么递推
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int INF = 0x3f3f3f3f;
        vector<int> lMax(n, -1); //[0...i]上严格小于nums[i]的最大值
        vector<int> rMax(n, -1); // 递减
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                lMax[i] = max(lMax[i - 1], nums[i - 1]);
            } else {
                int j = i - 1;
                while (j >= 0 && lMax[j] >= nums[i]) {
                    --j;
                }
                lMax[i] = lMax[j];
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i]>nums[i+1]){
                rMax[i] = max(rMax[i+1],nums[i+1]);
            } else{
                int j = i + 1;
                while (j <n && rMax[j] >= nums[i]) {
                    ++j;
                }
                lMax[i] = lMax[j];
            }
        }

        //        元素和最小
        int minSum = INT_MAX;

        for (int j = 0; j < n; ++j) {   // 枚举j
            if (j == 0 || j == n - 1) { // 不可能
                continue;
            }
            // 双指针，两侧开始找
            int i = 0;
            while (i < j) {
            }

            int k = n - 1;
            while (k > j) {
            }
            minSum = min(minSum, lMax[j - 1] + rMax[j + 1] + nums[j]);
        }

        return minSum == INT_MAX ? -1 : minSum; // 不存在
    }
};

int main() {
    Solution solution;
    // nums = [8,6,1,5,3]
    vector<int> nums = {8, 6, 1, 5, 3};
    // nums = [5,4,8,7,10,2]
    //        vector<int> nums = {5,4,8,7,10,2};
    // nums = [6,5,4,3,4,5]
    //        vector<int> nums = {6,5,4,3,4,5};
    //    cout << solution.minimumSum(nums) << endl;
    int n = nums.size();
    vector<int> lMax(n, -1); // 初始化为-1，表示没有找到
    vector<int> rMax(n, -1);

    // 计算 lMax
/*    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            lMax[i] = max(lMax[i], nums[s.top()]);
            s.pop();
        }
        if (!s.empty()) {
            lMax[i] = max(lMax[i], lMax[s.top()]);
        }
        s.push(i);
    }

    // 清空栈
    while (!s.empty()) {
        s.pop();
    }

    // 计算 rMax
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            rMax[i] = max(rMax[i], nums[s.top()]);
            s.pop();
        }
        if (!s.empty()) {
            rMax[i] = max(rMax[i], rMax[s.top()]);
        }
        s.push(i);
    }*/

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            lMax[i] = max(lMax[i - 1], nums[i - 1]);
        } else {
            int j = i - 1;
            while (j >= 0 && lMax[j] >= nums[i]) {
                --j;
            }
            lMax[i] = lMax[j];
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (nums[i]>nums[i+1]){
            rMax[i] = max(rMax[i+1],nums[i+1]);
        } else{
            int j = i + 1;
            while (j <n && rMax[j] >= nums[i]) {
                ++j;
            }
            lMax[i] = lMax[j];
        }
    }

    // lmax
    for (int i = 0; i < n; i++) {
        cout << lMax[i] << " ";
    }

    cout << endl;
    // rmax
    for (int i = 0; i < n; i++) {
        cout << rMax[i] << " ";
    }
    cout << endl;

    return 0;
}