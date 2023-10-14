//
// Created by Legion on 2023/10/8.
//

#include <bits/stdc++.h>

using namespace std;
//@date 2023-10-08
class Solution {
public:
    // 每颗处理器分4个任务
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        int m = processorTime.size();
        int n = tasks.size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = max(ans, processorTime[i] + tasks[n - 4 * i - 1]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    //    processorTime = [8,10], tasks = [2,2,3,1,8,7,4,5]
    vector<int> processorTime = {8, 10};
    vector<int> tasks = {2, 2, 3, 1, 8, 7, 4, 5};
    cout << solution.minProcessingTime(processorTime, tasks) << endl;

    return 0;
}