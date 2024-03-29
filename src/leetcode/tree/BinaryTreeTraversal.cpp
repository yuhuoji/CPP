/**
 * 144, 94, 145
 *
 * TODO
 */
#include <iostream>
#include <stack>
#include <vector>

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

class Solution1 {
private:
    void recursiveorderProcess(vector<int>& list, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        list.push_back(root->val); // 前序
        recursiveorderProcess(list, root->left);
        list.push_back(root->val); // 中序
        recursiveorderProcess(list, root->right);
        list.push_back(root->val); // 后序
    }
    void preorderProcess(vector<int>& list, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        list.push_back(root->val); // 前序
        preorderProcess(list, root->left);
        preorderProcess(list, root->right);
    }
    void inorderProcess(vector<int>& list, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorderProcess(list, root->left);
        list.push_back(root->val); // 中序
        inorderProcess(list, root->right);
    }
    void postorderProcess(vector<int>& list, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        postorderProcess(list, root->left);
        postorderProcess(list, root->right);
        list.push_back(root->val); // 后序
    }

public:
    /**
     * 递归
     */
    vector<int> recursiveorderTraversal(TreeNode* root) {
        vector<int> list;
        recursiveorderProcess(list, root);
        return list;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> list;
        preorderProcess(list, root);
        return list;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> list;
        inorderProcess(list, root);
        return list;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        postorderProcess(list, root);
        return list;
    }
};
/**
 * 手动维护
 */
class Solution2 {
public:
    // 前序 中左右
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) { // 空
            return res;
        }
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            if (root != nullptr) {
                res.push_back(root->val); // 处理当前节点
                stk.push(root);
                root = root->left;        // 左子树
            } else {                      // 遍历完中左
                root = stk.top();
                stk.pop();
                root = root->right; // 右子树
            }
        }
        return res;
    }
    // 中序 左中右
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) { // 空
            return res;
        }
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            if (root != nullptr) { //
                stk.push(root);
                root = root->left; // 左子树
            } else {               // 遍历完左
                root = stk.top();
                stk.pop();
                res.push_back(root->val); // 处理当前节点
                root = root->right;       // 右子树
            }
        }
        return res;
    }
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        res.push_back(root->val);
        stk.push(root);
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left; // 左子树
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right; // 右子树
        }
        return res;
    }
    // 后序 左右中
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> stk;
        TreeNode* lastVisited = nullptr; // 保存上次遍历到的节点

        while (root != nullptr || !stk.empty()) {
            if (root != nullptr) {
                stk.push(root);
                root = root->left;                                                // root = nullptr 左子树
            } else {                                                              // 遍历完左或左右中了
                TreeNode* topNode = stk.top();                                    // 当前节点
                if (topNode->right != nullptr && topNode->right != lastVisited) { // 遍历完左子树
                    root = topNode->right;                                        // 右子树
                } else {                                                          // 右子树遍历完了
                    stk.pop();
                    res.push_back(topNode->val);                                  // 处理当前节点
                    lastVisited = topNode;
                }
            }
        }
        return res;
    }
};

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    //    1
    //  2   3
    // 4 5

    Solution2 s2;
    vector<int> res = s2.postorderTraversal(root);
    // 输出res
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}