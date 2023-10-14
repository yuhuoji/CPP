//
// Created by Legion on 2023/10/8.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // sum - 2n_2

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

    return 0;
}