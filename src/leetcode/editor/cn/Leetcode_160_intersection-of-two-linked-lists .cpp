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
    int getLinkedListLength(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    // 先遍历一遍找到长度
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = getLinkedListLength(headA);
        int lengthB = getLinkedListLength(headB);

        int length = min(lengthA, lengthB);        // 较短的长度
        int diff = max(lengthA, lengthB) - length; // 长度差

        ListNode* pA = headA;
        ListNode* pB = headB;
        if (lengthA >= lengthB) {
            while ((diff--) > 0) {
                pA = pA->next;
            }
        } else {
            while ((diff--) > 0) {
                pB = pB->next;
            }
        }

        // 剩余长度相同
        while ((length--) > 0) {
            if (pA == pB) {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }

    // 双指针,都走(m-k)+k+(m-k)的长度，如果有交点，一定会相遇
    ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode* p = headA;
        ListNode* q = headB;
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
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
    string listA = "[4,1,8,4,5]", listB = "[5,6,1,8,4,5]";
    ListNode* headA = stringToListNode(listA);
    ListNode* headB = stringToListNode(listB);
    //    ListNode* ans1 = solution.getIntersectionNode1(headA, headB);
    //    cout << "ans1 : " << ans1 << endl;
    //    ListNode* ans2 = solution.getIntersectionNode2(headA, headB);
    //    cout << "ans2 : " << ans2->val << endl;
    return 0;
}