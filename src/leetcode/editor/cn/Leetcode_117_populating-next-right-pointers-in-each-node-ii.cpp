#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution117 {
// leetcode submit region begin(Prohibit modification and deletion)
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node()
        : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val)
        : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    // TODO @date 2023-11-03其他方法
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        vector<Node*> q = {root};
        while (!q.empty()) {
            vector<Node*> next;
            for (int i = 0; i < q.size(); ++i) {
                Node* cur = q[i];
                if (i > 0) { // q[i-1]是同一层的上一个节点
                    q[i - 1]->next = cur;
                }
                if (cur->left) {
                    next.push_back(cur->left);
                }
                if (cur->right) {
                    next.push_back(cur->right);
                }
            }
            q = std::move(next);
        }
        return root;
    }

    // bfs 队列
    Node* connect1(Node* root) {
        if (!root) {
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            Node* pre = q.front();
            q.pop();
            if (pre->left) {
                q.push(pre->left);
            }
            if (pre->right) {
                q.push(pre->right);
            }
            for (int i = 1; i < sz; ++i) {
                Node* cur = q.front();
                q.pop();
                pre->next = cur;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                pre = cur;
            }
        }
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution117

using namespace solution117;
int main() {
    std::cout << "Leetcode "
              << "117" << std::endl;
    Solution solution;

    vector<int> nums = {1, 2, 3};
    vector<int> nums2 = {1, 1, 1};

    nums = std::move(nums2);

    return 0;
}