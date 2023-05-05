/**
 * @date 2023-05-04
 * 基于业务的题目
 * 517. Super Washing Machines
 * Packing Machine
 */
#include <iostream>
#include <vector>
class Solution {
public:
    /**
     *
     */
    int findMinMoves(vector<int>& machines)  {
        if (machines.empty()) {
            return 0;
        }
        int size = machines.size();
        int sum = 0; // 衣服总数
        for (int i = 0; i < size; i++) {
            sum += machines[i];
        }
        if (sum % size != 0) { // 无法整除，一定无法平均分配
            return -1;
        }
        int avg = sum / size;                                                // 每台机器平均需要的衣服数
        int leftSum = 0;                                                     // 左侧已经有的衣服数
        int ans = 0;
        for (int i = 0; i < size; i++) {                                     // 遍历每个位置, 0~i-1 i i+1~n-1
            int leftRest = leftSum - i * avg;                                // 左侧(0 ~ i-1)需要更改的数量，正数表示多了，负数表示少了
            int rightRest = (sum - leftSum - machines[i]) - (size - i - 1) * avg; // 右侧(i+1 ~ n-1)需要更改的数量，负数表示少了，正数表示多了
            if (leftRest < 0 && rightRest < 0) {                             // 左侧和右侧都需要，从i位置送给左侧和右侧
                ans = max(ans, abs(leftRest) + abs(rightRest));
            } else {                                                         // 左侧或右侧只有一个需要，从多的送给少的
                ans = max(ans, max(abs(leftRest), abs(rightRest)));
            }
            leftSum += machines[i];
        }
        return ans;
    }
};
int main() {
}