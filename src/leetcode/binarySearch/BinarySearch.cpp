#include "bits/stdc++.h"
using namespace std;
class BinarySearch {
public:
    // 二分，找到第一个 >= target的位置
    // 闭区间写法[l,r]
    // *第一个>=target的位置
    // 四种可以相互转换(整数)
    // 最后一个<target的位置 binarySearch(>=target) - 1
    // 第一个>target的位置 binarySearch(>=target+1)
    // 最后一个<=target的位置, 转换成binarySearch(>target) - 1, binarySearch(>=target+1) - 1
    int binarySearch(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) { // 最后一次循环
            int m = ((r - l) >> 1) + l;
            if (target > nums[m]) {
                l = m + 1; //[l-1]一定小于target
            } else {
                r = m - 1; //[r+1]一定大于等于target
            }
        }
        // 循环结束r+1=l
        // r表示最后一个小于target的位置，l表示第一个大于等于target的位置
        return l; // 返回第一个大于等于target的位置
    }
};
int main() {
    BinarySearch solution = BinarySearch();
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 7;

    // 第一个>=target
    int ans = solution.binarySearch(nums, target);
    cout << "position : " << solution.binarySearch(nums, target) << ", ans : " << nums[solution.binarySearch(nums, target)] << endl;

    // 第一个>target
    cout << "position : " << solution.binarySearch(nums, target + 1) << ", ans : " << nums[solution.binarySearch(nums, target + 1)] << endl;

    // 最后一个<=target
    cout << "position : " << solution.binarySearch(nums, target + 1) - 1 << ", ans : " << nums[solution.binarySearch(nums, target + 1) - 1] << endl;

    // 最后一个<target
    cout << "position : " << solution.binarySearch(nums, target) - 1 << ", ans : " << nums[solution.binarySearch(nums, target) - 1] << endl;

    return 0;
}