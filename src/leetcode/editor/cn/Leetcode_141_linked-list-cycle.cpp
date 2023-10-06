#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution141 {
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 双指针
    // 快慢指针
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
    }

    bool hasCycle2(ListNode* head) {
        if (!head) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != slow) {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }

    // hash 第一个出现重复的值就是 空间O(N)
    bool hasCycle1(ListNode* head) {
        unordered_set<ListNode*> s;
        ListNode* cur = head;
        while (cur) {
            if (s.count(cur)) {
                return true;
            } else {
                s.insert(cur);
                cur = cur->next;
            }
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution141

using namespace solution141;
int main() {
    std::cout << "Leetcode "
              << "141" << std::endl;
    Solution solution;

    return 0;
}