//
// Created by yuhuoji on 2023/10/29.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // TODO @date 2023-10-29
    //
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
    }

    // 不知道什么类型？
    // 长度为3的子数组
    // 滑动窗口？
    long long minIncrementOperations(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int l = 0, r = 0;
        deque<int> q;
        int pre = -1;
        for (; r < k; ++r) {
            while (!q.empty() && nums[r] >= nums[q.back()]) { // 不可能为滑动窗口最大值了
                q.pop_back();
            }
            q.push_back(r);
        }
        pre = q.front();
        ans += k - nums[q.front()];

        for (; r < n; ++l, ++r) {
            while (!q.empty() && nums[r] >= nums[q.back()]) { // 不可能为滑动窗口最大值了
                q.pop_back();
            }
            q.push_back(r);
            while (q.front() <= l) {
                q.pop_front();
            }
            if (q.front() != pre) {
                ans += nums[q.front()] - nums[l];
                pre = q.front();
            }
        }
        return ans;
    }

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        int cnt1 = 0;
        for (auto num : nums1) {
            if (num == 0) {
                cnt1++;
            } else {
                sum1 += num;
            }
        }
        long long sum2 = 0;
        int cnt2 = 0;
        for (auto num : nums2) {
            if (num == 0) {
                cnt2++;
            } else {
                sum2 += num;
            }
        }

        if ((cnt1 == 0 && sum2 + cnt2 > sum1) || (cnt2 == 0 && sum1 + cnt1 > sum2)) {
            return -1;
        }

        return max(sum1 + cnt1, sum2 + cnt2);
    }

    //  2917位运算
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0; // K-or

        for (int i = 0; i < 32; ++i) { // i位，0..31
            int cnt = 0;
            for (auto x : nums) { // 枚举所有数
                cnt += (x >> i & 1);
            }
            if (cnt >= k) {
                ans |= (1 << i); //
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    //        vector<int> nums = {10,8,5,9,11,6,8};
    //        int k = 1;
    //        cout << solution.findKOr(nums, k) << endl;

    //        int num = 12 && (1 << 0);
    //        cout << nums << endl;

    //    vector<int> nums1 = {3,2,0,1,0}, nums2 = {6,5,0};
    //    cout << solution.minSum(nums1, nums2) << endl;

    vector<int> nums = {2, 3, 0, 0, 2};
    int k = 4;
    cout << solution.minIncrementOperations(nums, k) << endl;

    return 0;
}