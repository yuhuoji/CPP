/**
 * @date 2023-05-18
 * 剑指 Offer 36. 二叉搜索树与双向链表
 * 搜索二叉树转成双向链表
 * 二叉树的递归套路
 *
 */

class Solution {
private:
    /**
     * 返回头和尾
     */
    Info process(Node* node) {
        if (node == nullptr) {
            return Info(nullptr, nullptr);
        }
        Info leftHeadEnd = process(node->left);
        Info rightHeadEnd = process(node->right);
        if (leftHeadEnd.end != nullptr) { //
            leftHeadEnd.end->right = node;
        }
        node->left = leftHeadEnd.end;
        node->right = rightHeadEnd.start;
        if (rightHeadEnd.start != nullptr) {
            rightHeadEnd.start->left = node;
        }

        return Info(leftHeadEnd.start != nullptr ? leftHeadEnd.start : node,
                    rightHeadEnd.end != nullptr ? rightHeadEnd.end : node);
    }

public:
    /**
     * 返回双向链表的头节点
     */
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        return process(root).start; // 返回双向链表的头节点
    }
};

struct Info {
    Node* start;
    Node* end;
    Info(Node* start, Node* end)
        : start(start), end(end) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};