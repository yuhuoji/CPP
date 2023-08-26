#include <iostream>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    int height;
};

// 获取节点的高度
int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// 计算节点的平衡因子
int getBalanceFactor(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// 更新节点的高度
void updateHeight(TreeNode* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 左旋操作
TreeNode* leftRotate(TreeNode* root) {
    TreeNode* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

// 右旋操作
TreeNode* rightRotate(TreeNode* root) {
    TreeNode* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

// 插入节点到平衡二叉树中
TreeNode* insertNode(TreeNode* root, int key) {
    if (root == nullptr) {
        TreeNode* newNode = new TreeNode();
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    // 进行平衡调整
    if (balanceFactor > 1 && key < root->left->key) {
        // 左左情况，进行右旋操作
        return rightRotate(root);
    }

    if (balanceFactor < -1 && key > root->right->key) {
        // 右右情况，进行左旋操作
        return leftRotate(root);
    }

    if (balanceFactor > 1 && key > root->left->key) {
        // 左右情况，先对左子树进行左旋，再对根节点进行右旋
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balanceFactor < -1 && key < root->right->key) {
        // 右左情况，先对右子树进行右旋，再对根节点进行左旋
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// 中序遍历平衡二叉树
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->key << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    // 画出树的结构
    //     4
    //    / \
    //   2   6
    //  / \ / \
    // 1  3 5  7

    std::cout << "Inorder traversal of the AVL tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
