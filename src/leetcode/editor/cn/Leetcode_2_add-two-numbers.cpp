#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution2 {
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }

        if (carry > 0) {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }

        return head;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution2

using namespace solution2;
int main() {
    std::cout << "Leetcode " << 2 << std::endl;
    Solution solution = Solution();

    return 0;
}