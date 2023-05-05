/**
 * @date 2023-05-05
 * 48. Rotate Image
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    /**
     * 顺时针旋转以(a,b)(c,d)为边框
     * (a,b)(a,d)
     * (c,b)(c,d)
     * -------------
     * (a,b+i)(a+i,d)
     * (c-i,b)(c,d-i)
     */
    static void rotateEdge(vector<vector<int>>& matrix, int a, int b, int c, int d) {
        int temp;
        for (int i = 0; i < d - b; i++) { // b-d组
            temp = matrix[a][b + i];
            matrix[a][b + i] = matrix[c - i][b];
            matrix[c - i][b] = matrix[c][d - i];
            matrix[c][d - i] = matrix[a + i][d];
            matrix[a + i][d] = temp;
        }
    }

public:
    /**
     *matrix 正方形
     */
    static void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) { //{} {{}}
            return;
        }
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        if (dR != dC) { // row!=column
            return;
        }
        int tR = 0, tC = 0;
        while (tR < dR) { //(tR,tC)(dR,dC)
            rotateEdge(matrix, tR++, tC++, dR--, dC--);
        }
    }
    static void printMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) { //{} {{}}
            return;
        }
        int row = matrix.size();
        int column = matrix[0].size();
        // 二维数组打印
        for (int r = 0; r != matrix.size(); r++) {
            for (int c = 0; c != matrix[0].size(); c++) {
                cout << matrix[r][c] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    Solution::printMatrix(matrix);
    Solution::rotate(matrix);
    Solution::printMatrix(matrix);
}