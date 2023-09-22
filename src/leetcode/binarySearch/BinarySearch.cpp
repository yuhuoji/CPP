#include "bits/stdc++.h"
using namespace std;
class BinarySearch {
public:
    // 两两成对出现
    // 第一个>=target的位置
    // 最后一个<target的位置
    // 第一个>target的位置
    // 最后一个<=target的位置
    int binarySearch(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) { // 最后一次循环 l=r
            int m = ((r - l) >> 1) + l;
            if (nums[m] <= target) { // 修改if中的符号
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        // 循环结束 r+1 = l
        //...l, r ...
        //  <=, >
        //  < , >=
        return l; // 修改返回值l or r
    }
};
int main() {
    BinarySearch solution = BinarySearch();
    vector<int> nums = {1, 2, 3, 3, 3, 4, 6, 7};
    int target = 3;
    int ans = solution.binarySearch(nums, target);
    cout << "position : " << ans << ", num : " << nums[ans] << endl;

    return 0;
}