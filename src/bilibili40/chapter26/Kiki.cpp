/**
 * @date 2023-06-24
 * 增加递归的base case
 * 1.利用平凡解，可以终止递归(求最小值，某个解大于平凡解)
 * 2.从业务中发现可以不用进行后序的条件
 */
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;
class Solution {
private:
    /**
     * preMoney 当前花费的钱
     * aim 目标
     * add, times, del +2 *2 -2的花费
     * current 当前来到的人气
     * limitAim 尝试人气的最大值
     * limitCoin 尝试钱数的最大值
     */
    static int process(int preMoney, const int aim, const int add, const int times, const int del, int current,
                       const int limitAim, const int limitCoin) {
        // base case
        if (preMoney > limitCoin) { // 尝试的钱超过平凡解
            return std::numeric_limits<int>::max();
        }
        if (current < 0) {
            return std::numeric_limits<int>::max();
        }
        if (current > limitAim) { // 尝试的人气值超过aim*2
            return std::numeric_limits<int>::max();
        }

        if (aim == current) {
            return preMoney;
        }

        int minValue = std::numeric_limits<int>::max();
        // 人气值+2
        int p1 = process(preMoney + add, aim, add, times, del, current + 2, limitAim, limitCoin);
        if (p1 != std::numeric_limits<int>::max()) {
            minValue = p1;
        }
        // 人气值-2
        int p2 = process(preMoney + del, aim, add, times, del, current - 2, limitAim, limitCoin);
        if (p2 != std::numeric_limits<int>::max()) {
            minValue = min(minValue, p2);
        }
        // 人气值*2
        int p3 = process(preMoney + times, aim, add, times, del, current * 2, limitAim, limitCoin);
        if (p3 != std::numeric_limits<int>::max()) {
            minValue = min(minValue, p3);
        }
        return minValue;
    }

public:
    // current和aim都是偶数，current<=aim
    static int minCoins1(const int add, const int times, const int del, int current, int aim) {
        if (current > aim) {
            return -1;
        }
        // aim不会超过aim*2
        // 平凡解
        return process(0, aim, add, times, del, current, aim * 2, ((aim - current) / 2) * add);
    }
};
int main() {
    cout << std::numeric_limits<int>::max() << endl;
}