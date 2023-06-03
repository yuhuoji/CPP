/**
 * @date 2023-06-02
 * leetcode 501. Find Mode in Binary Search Tree

*/
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    void dfs(Node* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        update(root->val); // 中序遍历
        dfs(root->right);
    }
    void update(int value) {
        if (value == base) {
            ++count;
        } else {
            base = value;
            count = 1;
        }
        // count
        if (count == maxCount) {
            answer.push_back(base); // 同样是众数
        }
        if (count > maxCount) {
            maxCount = count; // 众数
            answer.clear();
            answer.push_back(base);
        }
    }

public:
    vector<int> answer;
    int base;     // 当前值
    int count;    // 当前次数
    int maxCount; // 最大次数

    vector<int> findMode1(Node* root) {
        dfs(root);
        return answer;
    }

    /**
     * morris遍历
     */
    vector<int> findMode2(Node* root) {
        Node* cur = root;
        Node* mostRight = nullptr;
        while (cur != nullptr) {
            mostRight = cur->left;
            if (mostRight == nullptr) { // 无左树
                update(cur->val);
                cur = cur->right;
                continue;
            }
            // 有左树,mostRight != nullptr
            while (mostRight->right != nullptr && mostRight->right != cur) { // 找到左树的最右节点，两种情况
                mostRight = mostRight->right;
            }
            // 已经找到左树的最右节点
            if (mostRight->right == nullptr) { // 第一次
                mostRight->right = cur;
                cur = cur->left;
            } else { // 第二次
                mostRight->right = nullptr;
                update(cur->val);
                cur = cur->right;
            }
        }
        return answer;
    }
};

int main() {
}