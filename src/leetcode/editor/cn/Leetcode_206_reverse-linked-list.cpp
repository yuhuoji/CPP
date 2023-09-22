#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution206 {
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
    //*** 递归
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    // 迭代
    ListNode* reverseList1(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) { // 翻转cur
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution206

using namespace solution206;
int main() {
    std::cout << "Leetcode "
              << "206" << std::endl;
    Solution solution = Solution();
    string list = "[1,2,3,4,5]";
    ListNode* head = stringToListNode(list);
    ListNode* res1 = solution.reverseList1(head);
    cout << listNodeToString(res1) << endl;
    ListNode* res = solution.reverseList(res1);
    cout << listNodeToString(res) << endl;

    return 0;
}