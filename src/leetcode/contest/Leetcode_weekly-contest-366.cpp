//
// Created by yuhuoji on 2023/10/8.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 8028
    // TODO @date 2023-10-08
    int minOperations(string s1, string s2, int x) {
        string diff = "";
        int count = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                diff += '0';
            } else {
                diff += '1';
                count++;
            }
        }
        if (count % 2) {
            return -1;
        }

        int ans = 0;
    }

    // 100085
    //  每颗处理器分4个任务
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

    // 100103
    //  sum - 2n_2

    int differenceOfSums(int n, int m) {
        int k = n / m;
        return n * (n + 1) / 2 - k * (k + 1) * m;
    }

    int differenceOfSums1(int n, int m) {
        int sum = 0, num1 = 0, num2 = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i;
        }

        for (int i = 1; i <= n; ++i) {
            if (i % m == 0) {
                num2 += i;
            }
        }

        return sum - 2 * num2;
    }
};

int main() {
    Solution solution;
    int n = 5, m = 1;
    cout << solution.differenceOfSums(n, m) << endl;

    //    processorTime = [8,10], tasks = [2,2,3,1,8,7,4,5]
    vector<int> processorTime = {8, 10};
    vector<int> tasks = {2, 2, 3, 1, 8, 7, 4, 5};
    cout << solution.minProcessingTime(processorTime, tasks) << endl;

    string s1 = "10110";
    string s2 = "00011";
    int x = 2;
    cout << solution.minOperations(s1, s2, x) << endl;

    //    string result = "";
    //    for (int i = 0; i < s1.size(); ++i) {
    //        if (s1[i] == s2[i]) {
    //            result += '0';
    //        } else {
    //            result += '1';
    //        }
    //    }
    //    cout << result << endl;

    return 0;
}