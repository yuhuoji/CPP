/**
 * @date 2023-04-24
 * n份青草，只能吃4的倍数份
 * 先后手都绝顶聪明
 * 
 * 292. Nim 游戏
 */
#include <iostream>
using namespace std;
class Eat {
private:
    /* data */
public:
    Eat(/* args */){

    };
    ~Eat(){

    };
    /**
     * 普通方法
     * 现在有n份，先手赢返回true，后手赢返回false
     */
    bool winner1(int n) {
        // 0  1  2  3  4
        // 后 先 后 先 先
        if (n < 5) {
            return (n == 0 || n == 2) ? false : true;
        }
        // n >= 5
        int base = 1;       // 先手决定吃的草
        while (base <= n) { // 先手吃掉base，后手吃n-base
            if (!winner1(
                    n -
                    base)) { // 如果后手吃掉n-base，返回（后手的）后手赢，那么先手现在吃base就是先手赢
                return true;
            }
            if (base > n / 4) { // 防止base*4溢出
                break;
            }
            base *= 4; // 从1 4 16 64依次尝试，是否有先手赢的可能
        }
        return false; // 没有先手赢的方案，后手赢
    }
    /**
     * 根据答案写的
     * 先手赢返回true，后手赢返回false
     */
    bool winner2(int n) {
        if (n % 5 == 0 || n % 5 == 2) {
            return false;
        } else {
            return true;
        }
    }
};
int main() {
    Eat eat;
    for (int i = 0; i < 50; i++) {
        cout << i << " = " << eat.winner1(i) << " : " << eat.winner2(i) << endl;
    }
}