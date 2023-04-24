/**
 *
 * @date 2023-04-24
 */
#include <iostream>
using namespace std;
class Solution {
private:
    /* data */
public:
    // 长度为L的绳子最长覆盖几个点，请保证arr有序
    int maxPoint(int *arr, int L, int arrayLength) {
        int res = 1;
        for (int i = 0; i < arrayLength; i++) {
            int nearest = nearestIndex(arr, i, arr[i] - L);
            res = max(res, i - nearest + 1);
        }
        return res;
    }
    // 在arr[0..R]范围上，找满足>=value 的最左位置
    int nearestIndex(int *arr, int R, int value) {
        int L = 0;
        int index = R;
        while (L <= R) {
            int mid = L + ((R - L) >> 1);
            if (arr[mid] >= mid) {
                index = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return index;
    }
    int minMoney(int *wus, int *mons) {
        return process(wus, mons, 0, 0);
    }
    // 0..i-1
    // wu 之前达到的武力值
    //
    int process(int *wus, int *mons, int i, int wu) {
        if (i == sizeof(wus) / sizeof(int)) {
            return 0;
        }
        if (wus[i] > wu) {
            return mons[i] + process(wus, mons, i + 1, wu + wus[i]);
        }
        return min(process(wus, mons, i + 1, wu), mons[i] + process(wus, mons, i + 1, wu + wus[i]));
    }
};

int main() {
    cout << "Hello World!!!" << endl;
    cout << "Hello World" << endl;
    int arr[] = {0, 13, 24, 35, 46, 57, 60, 72, 87};
    int arrayLength = sizeof(arr) / sizeof(arr[0]); // 计算数组长度
    Solution s;
    int L = 6;
    cout << "result = " << s.maxPoint(arr, L, arrayLength) << endl;
    return 0;
}