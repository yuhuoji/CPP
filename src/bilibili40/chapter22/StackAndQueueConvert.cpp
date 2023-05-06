/**
 * @date 2023-05-06
 * 用栈实现bfs（用栈实现队列）
 * 用队列实现dfs （用队列实现栈）
 */
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
/**
 * 用栈实现队列
 */
class TwoStacksQueue {
private:
    stack<int> stackPush;
    stack<int> stackPop;
    /**
     * stackPush -> stackPop
     */
    bool dump() {
        if (stackPop.empty()) { // 为空则不能倒数据
            return false;
        } else {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.pop());
            }
            return true;
        }
    }

public:
    TwoStacksQueue() {}
    ~TwoStacksQueue() {}
    void push(int val) {
        stackPush.push(val);
        dump();
    }
    int poll() {
        if (stackPop.empty() && stackPush) { // 都为空
            return;
        }
        dump(); // stackPush -> stackPop
        return stackPop.pop();
    }
    int peek() {
        if (stackPop.empty() && stackPush) { // 都为空
            return false;
        }
        dump();
        return stackPop.peek();
    }
};
/**
 * 用队列实现栈
 */
class TwoQueuesStack {
private: // 其中一个为空
    queue<int> queue1;
    queue<int> queue2;

public:
    TwoQueuesStack(/* args */) {}
    ~TwoQueuesStack() {}
    void push(int val) {
        queue<int> queue_use;
        queue<int> queue_empty;
        if (queue1.empty()) {
            queue_use = queue2;
            queue_empty = queue1;
        } else {
            queue_use = queue1;
            queue_empty = queue2;
        }
        queue_use.push(val);
    }
    int pop() {
        queue<int> queue_use;
        queue<int> queue_empty;
        if (queue1.empty()) {
            queue_use = queue2;
            queue_empty = queue1;
        } else {
            queue_use = queue1;
            queue_empty = queue2;
        }
        for (int i = 0; i < queue_use.size() - 1; i++) {
            queue_empty.push(queue_use.pop());
        }
        return queue_use.pop();
    }
    int peek() {
        queue<int> queue_use;
        queue<int> queue_empty;
        if (queue1.empty()) {
            queue_use = queue2;
            queue_empty = queue1;
        } else {
            queue_use = queue1;
            queue_empty = queue2;
        }
        return queue_use.back();
    }
};
int main() {
}