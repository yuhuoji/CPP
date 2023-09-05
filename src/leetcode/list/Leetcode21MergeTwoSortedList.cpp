/**
 * @date 2023-05-08
 * @file Leetcode21MergeTwoSortedList
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    /**
     * 递归
     */
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        if (!list1) { // l1空
            return list2;
        }
        if (!list2) { // l2空
            return list1;
        }
        // l1 and l2 均不为空
        if (list1->val < list2->val) { //
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    /**
     * 迭代
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* preHead = new ListNode(-1); // 哨兵
        ListNode* prev = preHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        // list1或list2可能未合并完
        prev->next = list1 ? list1 : list2;
        return preHead->next;
    }
};
int main() {
    ListNode* p = nullptr;
    cout << p << ", " << (p == nullptr) << " " << endl;
}