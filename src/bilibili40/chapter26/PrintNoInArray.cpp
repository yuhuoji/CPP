/**
 * @date 2023-06-04
 * 给定一个整数数组A,长度为n,有1<= A[i] <= n,且对于[1,n]的整数,其中部分整数会重复出现而部分不会出现。
 * 实现算法找到[1,n]中所有未出现在A中的整数。提示:尝试实现0(n)的时间复杂度和0(1)的空间复杂度(返回值不计入空间复杂度）。
 * 输入描述：一行数字,全部为整数,空格分隔
 * A0 A1 A2 A3...
 * 输出描述：一行数字,全部为整数,空格分隔RO R1 R2 R3...
 * 示例1:
 * 输入
 * 1343
 * 输出
 * 2
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    /**
     * 让value放在arr[value-1], 并继续直到终止
     *      1 2 3 ...
     * arr[ 0,1,2 ...]
     */
    static void modify(int value, vector<int>& arr) {
        while (arr[value - 1] != value) {
            int temp = arr[value - 1]; // 原来的值
            arr[value - 1] = value;
            value = temp;
        }
    }

public:
    /**
     * arr[0...n-1]的数字都在1~n之间
     */
    static void printNumberNoInArray(vector<int>& arr) {
        if (arr.size() == 0) {
            return;
        }
        for (auto value : arr) {
            modify(value, arr);
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != i + 1) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
};
int main() {
    vector<int> arr{3, 2, 3, 5, 6, 1, 6};
    Solution::printNumberNoInArray(arr);
}