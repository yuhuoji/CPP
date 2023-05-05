/**
 * @date 2023-05-01
 * 有N个相同的节点，可以组成多少种不同的二叉树
 * leetcode 96
 */
#include <iostream>
#include <vector>
using namespace std;
class UniqueBST {
private:
    /**
     * 树节点
     */
    class Node {
    public:
        int value;
        Node* left;
        Node* right;
        Node(){};
        Node(int value) {
            this->value = value;
        };
    };

public:
    /**
     * 递归
     */
    int process(int n) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) { // 空树
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int res = 0;                                         // result
        for (int leftNum = 0; leftNum <= n - 1; leftNum++) { // 左树从0 ~ n-1依次尝试，右树剩n - 1 - leftNum
            int leftWays = process(leftNum);                 // 左树方法数
            int rightWays = process(n - 1 - leftNum);        // 右树方法数
            res += leftWays * rightWays;
        }
        return res;
    }
    /**
     * 递归改的动态规划
     */
    int numTrees(int n) {
        if (n < 2) {
            return 1;
        }
        vector<int> dp(n + 1, 0); // n: 0 ~ N
        dp[0] = 1;                // 空树
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {         // 总节点数量为i时, 0 ~ N
            for (int j = 0; j <= i - 1; j++) { // 左侧数量为j, 0 ~ j-1，根节点1，右侧为i-j-1
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

int main() {
    UniqueBST uniqueBST;
    cout << uniqueBST.process(2) << " , " << uniqueBST.numTrees(2) << endl;
    return 0;
}
