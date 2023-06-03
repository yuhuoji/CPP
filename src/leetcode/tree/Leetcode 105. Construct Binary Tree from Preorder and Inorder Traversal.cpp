/**
 * @date 2023-05-20
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 * TODO
 */
#include <iostream>
#include <unordered_map>
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
    unordered_map<int, int> index;
    Node* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) {
            return nullptr;
        }
        int preorderRoot = preorderLeft;                       // 先序遍历第一个是根节点
        int inorderRoot = index[preorder[preorderRoot]];       // 中序遍历根节点
        Node* root = new Node(preorder[preorderRoot]); // 根节点
        int leftSubtreeSize = inorderRoot - inorderLeft;       // 左子树个数
        // 先序 [root， 左子树，右子树]
        //[preorderRoot]，[preorderLeft+1 ~ preorder + leftSubtreeSize]，[preorder + leftSubtreeSize + 1 ~ preorderRight]
        // 中序 [左子树，root，右子树]
        //[inorderLeft ~ inorderRoot - 1]，[inorderRoot]，[inorderRoot ~ inorderRight]
        root->left = myBuildTree(preorder, inorder, preorderLeft + 1, preorderLeft + leftSubtreeSize, inorderLeft, inorderRoot - 1);

        root->right = myBuildTree(preorder, inorder, preorderLeft + leftSubtreeSize + 1, preorderRight, inorderRoot+1, inorderRight);

        return root;
    }

public:
    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); // 哈希表
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
int main(){
    
}