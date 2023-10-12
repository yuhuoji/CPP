#include "bits/stdc++.h"
using namespace std;
class BinarySearch {
public:
    int binarySearch(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) { // 最后一次循环 l=r, 搜索的范围[l...r]
            int m = ((r - l) >> 1) + l;
            if (nums[m] >= target) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    // 两两成对出现
    // 第一个>=target的位置
    // 最后一个<target的位置
    // 第一个>target的位置
    // 最后一个<=target的位置
    int binarySearch1(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) { // 最后一次循环 l=r, 搜索的范围[l...r]
            int m = ((r - l) >> 1) + l;
            // target <= nums[m]表示l左侧严格小于target，r右侧大于等于target， < l , r >=
            // target < nums[m]表示l左侧小于等于target，r右侧严格大于target， <= l , r >
            if (target <= nums[m]) { // 尝试修改if中的符号<= < > >=
                r = m - 1;
            } else { // m [l...r]
                l = m + 1;
            }
        }
        // 循环结束 r+1 = l
        //... l , r ...
        //    <=, >
        // or  < , >=
        return r; // 尝试修改返回值l or r
    }
};
int main() {
    BinarySearch solution = BinarySearch();
    vector<int> nums = {1, 2, 3, 3, 3, 4, 6, 7};
    int target = 9;
    int ans = solution.binarySearch(nums, target);
    cout << "position : " << ans << ", num : " << nums[ans] << endl;

    return 0;
}