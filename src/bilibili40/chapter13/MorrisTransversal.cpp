/**
 * @date 2023-05-31
 * morris遍历的实质
 * 建立一种机制，对于没有左子树的节点只到达一次，对于有左子树的节点会到达两次
 *
 * Morris遍历
 * 假设来到当前节点cur，开始时来到根节点位置
 * 1）如果cur没有左孩子，cur向右移动（cur = cur.right）
 * 2）如果cur有左孩子，找到左子树上最右的节点mostRight：
 * a）如果mostRight的右指针指向空，让其指向cur，然后向左移动（cur = cur.left）
 * b）如果mostRight的右指针指向cur，让其指向null，然后cur向右移动（cur = cur.right）
 * 3）cur为空时遍历停止
 *
 * leetcode 501
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
private:
    /* data */
public:
    /**
     * morris注释
     */
    static void morris(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        TreeNode* cur = head;
        TreeNode* mostRight = nullptr;
        while (cur != nullptr) {
            mostRight = cur->left;                                        // cur是否有左树
            if (mostRight != nullptr) {                                   // cur有左树
                while (mostRight->right != nullptr && mostRight != cur) { // 找到左树的最右节点，两种情况
                    mostRight = mostRight->right;
                }
                // 已经找到左树的最右
                if (mostRight == nullptr) { // 第一次到达，将mostRight的右指针指向cur
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else { // 第二次到达，将mostRight的右指针设为null
                    mostRight->right = nullptr;
                }
            }
            cur = cur->right; // 没有左树，则向右树移动
        }
    }

static void morrisTraversal(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        if (!cur->left) {
            // 如果当前节点没有左子节点，则输出当前节点的值并进入右子节点
            std::cout << cur->val << " ";
            cur = cur->right;
            continue;
        }
        
        // 找到当前节点的左子树的最右节点
        TreeNode* mostRight = cur->left;
        while (mostRight->right && mostRight->right != cur) {
            mostRight = mostRight->right;
        }

        if (!mostRight->right) {
            // 如果最右节点的右指针为空，将其指向当前节点，并进入左子节点
            mostRight->right = cur;
            cur = cur->left;
        } else {
            // 如果最右节点的右指针指向当前节点，说明左子树已经遍历完毕，输出当前节点的值并进入右子节点
            mostRight->right = nullptr;
            std::cout << cur->val << " ";
            cur = cur->right;
        }
    }
}
};

int main() {
    // 构建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /*
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
     */

    // 使用 Morris 遍历二叉树
    Solution::morrisTraversal(root); //4 2 5 1 6 3 7

    return 0;
}