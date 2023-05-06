/**
 * @file start.cpp
 */
#include <iostream>
#include <stack>
using namespace std;

class Solution {
private:
    int ans = 0;

public:
    Solution(/* args */);
    ~Solution();
    static int add1(int val) {
        return ++val;
    }
    static int add2(int* val) {
        return ++(*val);
    }
    static int add3(int& val) {
        return ++val;
    }
};

int main() {
    cout << "Hello world" << endl;
    stack<long> stack;
    cout << "empty " << stack.empty() << endl;

    int num = 10;
    int* ptr = &num;
    int& ref = num;
    cout << num << " " << ptr << " " << ref << endl;
    cout << &num << " " << &ptr << " " << &ref << endl;
    cout << "*num"
         << " " << *ptr << " "
         << "*ref" << endl;
    Solution::add1(num);
    cout << " int " << num << "\n";
    Solution::add2(ptr);
    cout << " int* " << num << "\n";
    Solution::add3(ref);
    cout << " int& " << num << "\n";
    cout << endl;
}