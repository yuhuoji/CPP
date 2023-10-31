#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

namespace solution225 {
// leetcode submit region begin(Prohibit modification and deletion)
// 一个队列实现，记录当前队列内元素数量
class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        int sz = q.size();
        q.push(x);
        while (sz--) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

// 两个队列实现
class MyStack1 {
private:
    queue<int> q1, q2;

public:
    MyStack1() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int t = q1.front();
        q1.pop();
        return t;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// leetcode submit region end(Prohibit modification and deletion)

} // namespace solution225

using namespace solution225;
int main() {
    std::cout << "Leetcode "
              << "225" << std::endl;
    MyStack myStack;

    return 0;
}