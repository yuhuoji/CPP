/**
 * @date 2023-05-06
 * 155. Min Stack
 */
#include <iostream>
#include <limits.h>
#include <stack>

using namespace std;
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;

public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(min_stack.top(), val)); // 当前元素和最小栈顶的元素选最小的
    }

    void pop() { // 一起出栈
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};
/**
 * 不用额外空间的做法
 * 栈里存实际值与(当时的)最小值的差值
 * >0 不是最小值
 * <0 就是最小值(比之前的小)
 * =0 等于最小值
 */
class MinStack2 {
private:
    stack<long> stack; // long 防止溢出
    int min_value = INT_MIN;

public:
    MinStack2() {
    }

    void push(int val) {
        if (stack.empty()) { // 空栈，设置min
            min_value = val;
            stack.push(0);   // val - val = 0
        } else {
            int difference = val - min_value;
            stack.push((long) difference);
            min_value = difference < 0 ? val : min_value; // difference<0表示当前值更小，更新min
        }
    }

    void pop() {
        int top = (int) stack.top();
        min_value = top < 0 ? (min_value - top) : min_value; // 最小值出栈，更新最小值
        stack.pop();
    }

    int top() {
        return (int) stack.top() + min_value;
    }

    int getMin() {
        return min_value;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
    MinStack2 minstack;
    minstack.push(-2);
    minstack.push(0);
    minstack.push(-3);
    cout << minstack.getMin() << " ";
    minstack.pop();
    cout << minstack.top() << " ";
    cout << minstack.getMin() << " " << endl;
}