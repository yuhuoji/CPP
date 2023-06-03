/**
 * @date 2023-06-03
 * complete binary tree的节点个数
 */
#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node()
        : val(0), left(nullptr), right(nullptr) {}
    Node(int x)
        : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node* left, Node* right)
        : val(x), left(left), right(right) {}
};

class Solution {
private:
    /**
     * node在第level层，h是总的深度
     * 返回以node为头节点的树，节点总数是多少
     */
    int bs(Node* node, int level, const int h) {
        if (level == h) {
            return 1;
        }
        if (mostLeftLevel(node->right, level + 1) == h) {                 // 右树的最大深度到了h，则左树是满树perfect，左树高度h-level
            return (1 << (h - level)) + bs(node->right, level + 1, h);    // 2 ^ (h - level) - 1 + 1 + 右树
        } else {                                                          // 右树的最大深度没到h，右树是满的，右树高度h - level - 1
            return (1 << (h - level - 1)) + bs(node->left, level + 1, h); // 2 ^ (h - level -1) + 左树
        }
    }

    /**
     * 以node为头的树，当前节点node在第level层，
     * 返回最大深度
     * 走左边界
     */
    int mostLeftLevel(Node* node, int level) {
        while (node != nullptr) {
            ++level;
            node = node->left;
        }
        // node == nullptr
        return level - 1;
    }

public:
    /**
     * 以head为头的树，是完全二叉树
     * 递归O(h^2) = O((logN)2)
     */
    int nodeNum(Node* head) {
        if (head == nullptr) {
            return 0;
        }
        return bs(head, 1, mostLeftLevel(head, 1)); // 以head为头的树，当前在第1层，最大深度为mostLeftLevel(head, 1)
    }
};
int main() {
}