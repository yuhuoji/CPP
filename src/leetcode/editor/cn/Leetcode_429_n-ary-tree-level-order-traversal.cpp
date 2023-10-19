#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution429 {
// leetcode submit region begin(Prohibit modification and deletion)

// Definition for a Node.

/*class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size(); // 当前层的节点个数
//            vector<int> level;
            res.push_back(vector<int>());
            for (int i = 0; i < currentLevelSize; ++i) {
                Node* cur = q.front();
                q.pop();
                res.back().push_back(cur->val);
                for (Node* child : cur->children) { // 把子节点都加入
                    q.push(child);
                }
            }
//            res.push_back(move(level)); //
        }
        return res;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution429

using namespace solution429;
int main() {
    std::cout << "Leetcode "
              << "429" << std::endl;
    Solution solution;

    return 0;
}