#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution142 {
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
    // 长度 a+b
    // 第一次 f = 2s, f - s = nb
    // s = nb, 只需要 slow 再走 a 步
    // 让 fast 从头和 slow 一起走 a 步

    // 双指针
    // 快慢指针
    //TODO @date 2023-10-06 起点？
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {
            if (!fast || !fast->next) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                break;
            }
        }
        // slow 再走 a 步
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    // hash 空间 O(n)
};
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution142

using namespace solution142;
int main() {
    std::cout << "Leetcode "
              << "142" << std::endl;
    Solution solution;

    return 0;
}