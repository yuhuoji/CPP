/**
 * @date 2023-05-01
 * 数组arr，找到所有差值为k的去重数字对
 * TODO leetcode 532
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     *
     */
    int findPairs(vector<int>& nums, int k) {
    }
    vector<vector<string>> getGroups(string strArr[], int len) {
        unordered_map<int, vector<string>> map;
        for (int i = 0; i < len; i++) {
            if (strArr[i].length() != 0) {
                char str[strArr[i].length() + 1];
                strcpy(str, strArr[i].c_str());
                int counts = 0;
                for (int j = 0; j < strlen(str); j++) {
                    counts |= (1 << (str[j] - 'a'));
                }
                if (map.count(counts) == 0) {
                    vector<string> group;
                    group.push_back(strArr[i]);
                    map[counts] = group;
                } else {
                    map[counts].push_back(strArr[i]);
                }
            }
        }
        vector<vector<string>> result;
        for (auto& it : map) {
            result.push_back(it.second);
        }
        return result;
    }
};

int main() {
    cout << "111" << endl;
}