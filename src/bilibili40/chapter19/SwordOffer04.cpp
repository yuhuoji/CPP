/**
 * @date 2023-05-04
 * 剑指offer 04
 * 240. Search a 2D Matrix II
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1; // 从右上角开始
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                --j;
            } else { // matrix[i][j]<target
                ++i;
            }
        }
        return false;  
    }
};

int main() {
    cout << "Solution" << endl;
}