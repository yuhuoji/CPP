/**
 * @date 2023-05-07
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Fibonacci {
private:
    /**
     * 矩阵乘法 m1 * m2
     * O(1)
     */
    vector<vector<int>> multiMatrix(vector<vector<int>> m1, vector<vector<int>> m2) {
        vector<vector<int>> res(m1.size(), vector<int>(m2[0].size()));
        for (int i = 0; i < m1.size(); i++) {
            for (int j = 0; j < m2[0].size(); j++) {
                for (int k = 0; k < m2.size(); k++) {
                    res[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        return res;
    }

public:
    int fibonacci() {
        return 0;
    }
    /**
     * 斐波那契
     * O(logN)
     */
    int fibonacci2(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        //{F(N), F(N-1)} = {F(2), F(1)} * {{1, 1} , {1, 0}} ^ (N-2)
        vector<vector<int>> base(2, vector<int>(2, 1)); // 系数矩阵
        base[1][1] = 0;
        // 1 1
        // 1 0
        vector<vector<int>> res = matrixPower(base, n - 2);
        return res[0][0] + res[1][0];
    }
    /**
     * 快速幂（Exponentiation by squaring，平方求幂）
     * O(logN)
     * p 幂的二进制形式
     */
    vector<vector<int>> matrixPower(vector<vector<int>> matrix, int p) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < res.size(); i++) {
            res[i][i] = 1; // 单位矩阵
        }
        vector<vector<int>> t = matrix;
        for (; p != 0; p >>= 1) { // p = p >> 1;
            if ((p & 1) != 0) {
                res = multiMatrix(res, t);
            }
            t = multiMatrix(t, t); // 1 2 4 8 16 32 64
        }
        return res;
    }
};
int main() {
}