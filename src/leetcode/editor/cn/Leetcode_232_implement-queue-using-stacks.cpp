#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution232 {
// leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
private:
    stack<int> in_stack, out_stack;

    void in_to_out() { // 从输入栈颠倒到输出栈
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        if (out_stack.empty()) {
            this->in_to_out();
        }
        int t = out_stack.top();
        out_stack.pop();
        return t;
    }

    int peek() {
        if (out_stack.empty()) {
            this->in_to_out();
        }
        return out_stack.top();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution232

using namespace solution232;
int main() {
    std::cout << "Leetcode "
              << "232" << std::endl;
    MyQueue myQueue;

    return 0;
}