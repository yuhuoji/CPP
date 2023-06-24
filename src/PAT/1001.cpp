#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false); // 关闭同步
    std::cin.tie(nullptr);            // 解除绑定

    int a, b, symbol = 1;
    scanf("%d", &a);
    scanf("%d", &b);

    int ans = a + b;
    if (ans < 0) {
        symbol = -1;
        ans = -ans;
    }

    int group[3];
    int k = 0;
    do {
        group[k] = ans % 1000;
        ans /= 1000;

    } while (ans);

    if (symbol == -1) {
        printf("%c", '-');
    }

    printf("%d", group[--k]);

    while (k > 0) {
        printf(",%3d", group[--k]);
    }

    return 0;
}