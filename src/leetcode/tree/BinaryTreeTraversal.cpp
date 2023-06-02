/**
 * 94. Binary Tree Inorder Traversal
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
        process(list, root);
        return list;
    }
};

class Solution2 {
public:
    /**
     * 手动维护
     */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        res.push_back(root->val);
        stk.push(root);
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left; // 左树
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right; // 右树
        }
        return res;
    }
};

int main() {
}