/**
 * @date 2023-04-29
 * 给定苹果数量，用6和8的袋子来装，袋子只能装满或不装，求所用袋子的最少数量
 * 打表法 : int输入int输出类型，用普通正确方法打出结果，根据结果找规律写出代码。可以解决4成左右
 */
#include <iostream>
using namespace std;
class AppleMinBags {
private:
public:
    AppleMinBags() {
        cout << "Constructor called" << endl;
    }
    ~AppleMinBags() {
        cout << "Destructor called" << endl;
    }
    /**
     * 剩下的苹果能否用6装，不能则返回-1
     */
    int minBagBase6(int rest) {
        return rest % 6 == 0 ? (rest / 6) : -1;
    }
    /**
     * 使用的最少的袋子，无解返回-1
     */
    int minBag(int apple) {
        if (apple < 0) {
            return -1;
        }
        int bag6 = -1;
        int bag8 = apple / 8;
        int rest = apple - bag8 * 8;
        while (bag8 >= 0 && rest < 24) {
            int restUse6 = minBagBase6(rest);
            if (restUse6 != -1) {
                bag6 = restUse6;
                break;
            }
            --bag8;
            rest = apple - bag8 * 8;
        }
        return bag6 == -1 ? -1 : bag6 + bag8;
    }
    int minBagAwesome(int apple) {
        if ((apple & 1) != 0) { // apple为奇数返回
            return -1;
        }
        if (apple < 18) {
            return apple == 0                                    ? 0
                   : (apple == 6 || apple == 8)                  ? 1
                   : (apple == 12 || apple == 14 || apple == 16) ? 2
                                                                 : -1;
        }
        return (apple - 18) / 8 + 3;
    }
};

int main() {
    AppleMinBags myBag;

    cout << myBag.minBagBase6(48) << endl;

    for (int apple = 0; apple < 100; ++apple) { //输出结果，按照结果找规律
        cout << "apple = " << apple << " : " << myBag.minBag(apple) << " : "
             << myBag.minBagAwesome(apple) << endl;
    }

    return 0;
}
