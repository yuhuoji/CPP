//
// Created by yuhuoji on 2023/10/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //plus题
    //    给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长子数组长度。
    //        如果不存在任意一个符合要求的子数组，则返回 0。
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; //
        mp[0] = -1;                 // 0
        int sum = 0;                // 当前的累加和
        int max_len = 0;
        for (int j = 0; j < n; ++j) { // 枚举j，计算累加和
            sum += nums[j];
            if (mp.count(sum - k)) {
                max_len = max(max_len, j - mp[sum - k]);
            }
            if (!mp.count(sum)) { // 记录最早出现的位置
                mp[sum] = j;
            }
        }
        return max_len;
    }
};

int main() {
    Solution solution;
    // nums = [1, -1, 5, -2, 3], k = 3
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;

    return 0;
}