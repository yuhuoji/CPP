/**
 * @date 2023-05-06
 * 42. Trapping Rain Water
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * TODO
     * 从高至低，向两侧
     * /2
     */
    static int trap1(vector<int>& height) {
        int ans = 0;
        for (int i = 0; i < height.size(); i++) { // 所有位置
            // 每个位置向两侧查 0 ~ size-1
            int left = i - 1;
            while (left > 0 && height[left] < height[i]) { // left
                --left;
            }
            if (i != 0 && left > 0) {
                ans += (i - left - 1);
            }
            int right = i + 1;
            while (right < height.size() - 1 && height[right] < height[i]) { // right
                ++right;
            }
            if (i != height.size() - 1 && right < height.size() - 1) {
                ans += (right - i - 1);
            }
            cout << "i = " << i << ", ans = " << ans << endl;
        }
        return ans;
    }
    /**
     * 计算每个位置上方剩余的水
     * 双指针
     * 时间O(N) 空间O(1)
     */
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Solution::trap(height) << endl;
}