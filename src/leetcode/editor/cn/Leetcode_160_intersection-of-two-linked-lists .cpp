#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution160 {
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
private:
    // 翻转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode* findFirstHalfEnd(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    // TODO @date 2023-09-19 翻转链表
    // 翻转链表+快慢指针 找到交点
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        {
//            l1 = l1.next == null ? headB : l1.next;
//            l2 = l2.next == null ? headA : l2.next;
//        }
//    }

    // 双指针,都走(m-k)+k+(m-k)的长度，如果有交点，一定会相遇
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode* p = headA;
        ListNode* q = headB;
        while (p != q) {
            p = p->next ? p->next : headB;
            q = q->next ? q->next : headA;
            /*if (!p) {
                p = headB;
            } else {
                p = p->next;
            }
            if (!q) {
                q = headA;
            } else {
                q = q->next;
            }*/
        }
        return p;
    }

    ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> mpA;
        ListNode* p = headA;
        while (p) { // list A
            mpA.insert(p);
            p = p->next;
        }
        // list B
        p = headB;
        while (p) {
            if (mpA.count(p)) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution160

using namespace solution160;
int main() {
    std::cout << "Leetcode "
              << "160" << std::endl;
    Solution solution = Solution();
//    string listA = "[4,1,8,4,5]", listB = "[5,6,1,8,4,5]";
//    ListNode* headA = stringToListNode(listA);
//    ListNode* headB = stringToListNode(listB);
//    ListNode* ans1 = solution.getIntersectionNode1(headA, headB);
//    cout << "ans1 : " << ans1 << endl;
//    ListNode* ans2 = solution.getIntersectionNode2(headA, headB);
//    cout << "ans2 : " << ans2->val << endl;
    return 0;
}