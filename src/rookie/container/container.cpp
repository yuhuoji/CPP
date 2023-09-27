//
// Created by Legion on 2023/9/26.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
};

int main() {
    Solution solution;

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << "-------" << endl;

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    //
    cout << q.front() << endl;
    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    /*    set<string> mySet;
        map<int, string> myMap;
        unordered_set<string> unorderedSet;
        unordered_map<int, string> unorderedMap;
        vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        // 使用
        for (auto it = myVector.begin(); it != myVector.end(); ++it) {
            cout << *it << endl;
        }
        // 使用mySet
        mySet.insert("a");
        mySet.insert("b");
        // 查找
        if (mySet.find("a") != mySet.end()) {
            cout << "found: " << *mySet.find("a") << endl;
        }
        // 使用myMap
        myMap[1] = "a";
        myMap[2] = "b";
        // 查找
        if (myMap.find(1) != myMap.end()) {
            cout << "found: " << myMap.find(1)->first << " : " << myMap.find(1)->second << endl;
        }*/

    return 0;
}