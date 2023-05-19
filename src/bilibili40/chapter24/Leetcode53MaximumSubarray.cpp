/**
 * @date 2023-05-19
 * 子数组的最大累加和
 * leetcode 53
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    /* data */
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int maxNumber = INT_MIN; // 最大值
        int cur = 0;             // 当前和
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            maxNumber = max(maxNumber, cur); // 更新最大值
            cur = cur < 0 ? 0 : cur;         // 重置cur
        }
        return maxNumber;
    }
};