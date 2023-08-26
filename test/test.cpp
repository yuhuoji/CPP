#include <bits/stdc++.h>

using namespace std;

int main() {
    // C++
    // std::ifstream inputFile("in.txt");                    // 打开文件
    // std::ofstream outputFile("out.txt");
    // std::streambuf* originalCinBuffer = std::cin.rdbuf(); // 保存标准输入输出流
    // std::streambuf* originalCoutBuffer = std::cout.rdbuf();
    // std::cin.rdbuf(inputFile.rdbuf());                    // 将输入和输出重定向到文件流
    // std::cout.rdbuf(inputFile.rdbuf());

    // C
    freopen("in.txt", "r", stdin); //将标准输入重定向到文件
    freopen("out.txt", "w", stdout);

    int n, m;
    // scanf("%d %d", &n, &m);
    // printf("n = %d, m = %d\n", n, m);

    while (cin >> n) {
        cout << n << endl;
        if (n == 0)
            break;
    }

    cout << "Come on HuaWei, Come on China111" << endl;

    int a = 1, b = 2, c = 2;
    int res = (a + b + c) / 3.0 + 0.5;
    cout << "res = " << res << endl;

    // C++
    // inputFile.close();                 // 关闭文件
    // outputFile.close();
    // std::cin.rdbuf(originalCinBuffer); // 恢复标准输入
    // std::cout.rdbuf(originalCoutBuffer);

    // C
    fclose(stdin);
    fclose(stdout);

    while (cin >> n) {
        cout << n << endl;
        if (n == 0)
            break;
    }

    return 0;
}
