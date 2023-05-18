/**
 * @date 2023-05-09
 * runoob.com
 */
#include <iostream>
using namespace std;

class Box {
private:
public:
    double length;     // 长度
    Box()
        : length(0) {} 
    Box(double length)
        : length(length) {}
    Box operator+(const Box& b) { // 重载 + 运算符，用于把两个 Box 对象相加
        Box box;
        box.length = this->length + b.length;
        return box;
    }
    Box operator+(const int num) { // 重载+号用于对象与数相加
        return Box(this->length + num);
    }
    friend Box operator+(const int num, Box box) { //友元函数, 调用第二个重载+的成员函数
        return box + num;
    }
};

int main(void) {
    Box box1(1);
    Box box2(2);
    Box box3;
    cout << "box3.length = " << box3.length << endl;
    box3 =   box1+1;
    cout << "box3.length = " << box3.length << endl;
    return 0;
}