#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution234 {
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
private:
    // 翻转链表
    ListNode* reveseList(ListNode* head) {
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
    // 快慢指针
    ListNode* findEndOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    // 栈
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* p = head;
        while (p) {
            stk.push(p->val);
            p = p->next;
        }
        p = head;
        while (p) {
            if (p->val != stk.top()) {
                return false;
            }
            stk.pop();
            p = p->next;
        }
        return true;
    }
    // 快慢指针+翻转链表
    bool isPalindrome3(ListNode* head) {
        if (!head) {
            return true;
        }
        ListNode* fistHalfEnd = findEndOfFirstHalf(head);
        // 翻转
        ListNode* secondHalfStart = reveseList(fistHalfEnd->next);
        // 双指针检查
        ListNode* p = head;
        ListNode* q = secondHalfStart;
        bool result = true;
        while (result && q) {
            if (p->val != q->val) {
                result = false;
            }
            p = p->next;
            q = q->next;
        }
        // 复原
        fistHalfEnd->next = reveseList(secondHalfStart);
        return result;
    }

    // TODO @date 2023-09-20
    //  方法二：递归
    bool isPalindrome2(ListNode* head) {
        return true;
    }

    // 先复制到数组，再双指针
    bool isPalindrome1(ListNode* head) {
        vector<int> list;
        while (head) {
            list.emplace_back(head->val);
            head = head->next;
        }
        int n = list.size();
        /*int l = 0, r = n - 1;
        while (l <= r) {
            if (list[l] != list[r]) {
                return false;
            }
            l++;
            r--;
        }*/
        for (int l = 0, r = n - 1; l < r; ++l, --r) {
            if (list[l] != list[r]) {
                return false;
            }
        }
        return true;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution234

using namespace solution234;
int main() {
    std::cout << "Leetcode "
              << "234" << std::endl;
    Solution solution = Solution();
    string list = "[1,2,2,1]";
    ListNode* head = stringToListNode(list);
    cout << solution.isPalindrome(head) << endl;
    return 0;
}