/**
 * @date 2023-05-05
 * zigzag打印长方形
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    /**
     * (a,b)，(c,d)
     * fromUp 打印方向
     */
    static void printLevel(vector<vector<int>>& matrix, int ar, int ac, int br, int bc, bool fromUp) {
        if (fromUp) { // a -> b
            while (ar < br + 1) { //!=
                cout << matrix[ar++][ac--]<<" ";
            }
        } else { // b -> a
            while (br > ar - 1) { //!=
                cout << matrix[br--][bc++]<<" ";
            }
        }
    }

public:
    static void printZigZagMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) { //{} {{}}
            return;
        }
        int ar = 0, ac = 0;                                     //(ar,ac) ->右->下->
        int br = 0, bc = 0;                                     //(br,bc) ->下->右->
        int endR = matrix.size() - 1, endC = matrix.size() - 1; //(endR,endC)
        bool fromUp = false;
        while (ar != endR + 1) {
            printLevel(matrix, ar, ac, br, bc, fromUp); // 打印斜线
            //(ar,ac) ->右->下->
            ar = (ac == endC ? ar + 1 : ar); // 再往下
            ac = (ac == endC ? ac : ac + 1); // 先往右
            //(br,bc) ->下->右->
            bc = (br == endR ? bc + 1 : bc); // 再往右
            br = (br == endR ? br : br + 1); // 先往下
            fromUp = !fromUp;
        }
        cout << endl;
    }
};
int main() {
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    Solution::printZigZagMatrix(matrix);
}
