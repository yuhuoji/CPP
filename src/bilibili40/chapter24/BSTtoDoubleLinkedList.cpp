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
    Info process(TreeNode* node) {
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
    TreeNode* treeToDoublyList(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        return process(root).start; // 返回双向链表的头节点
    }
};

struct Info {
    TreeNode* start;
    TreeNode* end;
    Info(TreeNode* start, TreeNode* end)
        : start(start), end(end) {}
};

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {}

    TreeNode(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    TreeNode(int _val, TreeNode* _left, TreeNode* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};