//
// Created by Legion on 2023/9/26.
//

#include <bits/stdc++.h>

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
/*
 4
 a
 b
 c
 d
 3
 a b
 a c
 b c
 */
class Solution {
public:
    void chemical1() {
        int m, n;
        cin >> m;

        vector<string> chemicals(m);
        unordered_map<string, set<string>> compatibility;

        for (int i = 0; i < m; ++i) {
            cin >> chemicals[i];
        }

        cin >> n;
        for (int i = 0; i < n; ++i) { // 可以放在同一个盒子里而不会发生爆炸
            string a, b;
            cin >> a >> b;
            compatibility[a].insert(b); // a -> b
            compatibility[b].insert(a); // b -> a
        }

        for (int i = 0; i < m; ++i) { // 三层循环遍历chemicals[i]中的所有元素
            for (int j = i + 1; j < m; ++j) {
                for (int k = j + 1; k < m; ++k) {
                    bool safe = false;
                    if ((compatibility[chemicals[i]].count(chemicals[j]) > 0 && compatibility[chemicals[i]].count(chemicals[k]) > 0) ||
                        (compatibility[chemicals[j]].count(chemicals[i]) > 0 && compatibility[chemicals[j]].count(chemicals[k]) > 0) ||
                        (compatibility[chemicals[k]].count(chemicals[i]) > 0 && compatibility[chemicals[k]].count(chemicals[j]) > 0)) { // i -> j 或 i -> k 或 j -> k 存在
                        safe = true;
                    }

                    if (safe) {
                        cout << chemicals[i] << " " << chemicals[j] << " " << chemicals[k] << endl;
                    }
                }
            }
        }
    }

};
int main() {
    Solution solution;
    solution.chemical1();

    return 0;
}
