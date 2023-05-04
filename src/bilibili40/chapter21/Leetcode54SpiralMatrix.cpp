/**
 * @date 2023-05-04
 * 宏观调度
 * 剑指 Offer 29. 顺时针打印矩阵
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    /* data */
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }
        int tR = 0, tC = 0;                                    // 左上角
        int dR = matrix.size() - 1, dC = matrix[0].size() - 1; // 右下角
        while (tR <= dR && tC <= dC) { //两个点不越界
            printEdge(matrix,ans, tR++, tC++, dR--, dC--); //左上角和右下角向内缩小
        }
        return ans;
    }
    // 旋转，左上角(a,b)，右上角(c,d)
    void printEdge(vector<vector<int>>& matrix,vector<int>& ans, int a, int b, int c, int d) {
        if (a == c) { // 同一列，从上到下
            for (int i = b; i <= d; i++) {
                ans.push_back(matrix[a][i]);
            }
        } else if (b == d) { // 同一行，从左到右
            for (int i = a; i <= c; i++) {
                ans.push_back(matrix[i][b]);
            }
        } else {                // 不同行且不同列
            int curC = b;       // 列
            int curR = a;       // 行
            while (curC != d) { // 从左到右
                ans.push_back(matrix[a][curC]);
                curC++;
            }
            while (curR != c) { // 从上到下
                ans.push_back(matrix[curR][d]);
                curR++;
            }
            while (curC != b) { // 从右到左
                ans.push_back(matrix[c][curC]);
                curC--;
            }
            while (curR != a) { // 从下到上
                ans.push_back(matrix[curR][b]);
                curR--;
            }
        }
    }
};
int main() {
}
