/**
 * @date 2023-05-31
 * morris遍历的实质
 * 建立一种机制，对于没有左子树的节点只到达一次，对于有左子树的节点会到达两次
 *
 * Morris遍历
 * 假设来到当前节点cur，开始时来到头节点位置
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

class MorrisTransversal {
private:
    /* data */
public:
    /**
     * morris注释
     */
    void morris(TreeNode* head) {
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
};

int main() {
}