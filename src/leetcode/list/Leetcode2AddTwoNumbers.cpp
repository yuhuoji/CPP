/**
 * @date 2023-05-08
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 */
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0), next(nullptr) {}
    ListNode(int x)
        : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr; //头
        ListNode* tail = nullptr;
        int carry = 0;
        while (l1 || l2) { //
            int n1 = l1 ? l1->val : 0;                // l1
            int n2 = l2 ? l2->val : 0;                // l2
            int sum = n1 + n2 + carry;
            if (!head) {                              // head
                head = tail = new ListNode(sum % 10); //(n1+n2+carry)mod10
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10; // 进位
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        // l1 l2 均遍历结束
        if (carry > 0) { //最后一位进位
            tail->next = new ListNode(carry);
        }
        return head;
    }
};