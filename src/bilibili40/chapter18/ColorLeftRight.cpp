/**
 * @date 2023-04-29
 * 牛牛有一些排成一行的正方形。每个正方形已经被染成红色或者绿色。
 * 牛牛现在可以选择任意一个正方形然后用这两种颜色的任意一种进行染色,这个正方形的颜色将会被覆盖。
 * 牛牛的目标是在完成染色之后,每个红色R都比每个绿色G距离最左侧近。牛牛想知道他最少需要涂染几个正方形。
 * 如样例所示: s = RGRGR
 * 我们涂染之后变成GGRRR满足要求了,涂染的个数为2,没有比这个更好的涂染方案。
 * 
 * 染完后，分成两半，左侧全是G，右侧全是R
 * 
 * 技巧：预处理。当需要多次遍历时，可以先遍历并记录所需的信息，再每次查询记录便可 
 * 预处理数组，left数组存[0...i-1]里R的数量，right数组存[i..n-1]里G的数量
 * 再依次遍历，求得每个位置需要染的个数，求出最优解
 * TODO
 */
#include <iostream>
using namespace std;
class ColorLeftRight {
private:
    /* data */
public:
    ColorLeftRight(/* args */);
    ~ColorLeftRight();
    int minPaint(String s) {}
};

int main() {}

ColorLeftRight::ColorLeftRight() {}

ColorLeftRight::~ColorLeftRight() {}
