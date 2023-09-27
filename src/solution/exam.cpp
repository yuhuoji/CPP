//
// Created by Legion on 2023/9/27.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    int findMostFrequentNumber(const vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        int maxCount = 0;
        int maxNumber = -1;
        for (int num : nums) {
            if (m.find(num) == m.end()) {
                m[num] = 1;
            } else {
                m[num]++;
            }

            if (m[num] > maxCount) {
                maxCount = m[num];
                maxNumber = num;
            }
        }
        return maxNumber;
    }

public:
    void decompose(int N, string current) {
        if (N == 0) {
            cout << current << endl; // 输出分解结果
        } else if (N > 0) {
            // 分解为1的情况
            decompose(N - 1, current + "1");

            // 分解为3的情况
            if (N >= 3) {
                decompose(N - 3, current + "3");
            }
        }
    }

public:
    bool singlePeak(const vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int l = i;
            int r = i;
            if (i == 0 && nums[i] > nums[i + 1]) {
                while (r < n - 1) {
                    if (nums[r] <= nums[r + 1]) {
                        return false;
                    }
                    r++;
                }
            } else if (i == n - 1 && nums[i - 1] < nums[i]) {
                while (l > 0) {
                    if (nums[l - 1] >= nums[l]) {
                        return false;
                    }
                    l--;
                }
            } else if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                while (r < n - 1) {
                    if (nums[r] <= nums[r + 1]) {
                        return false;
                    }
                    r++;
                }
                while (l > 0) {
                    if (nums[l - 1] >= nums[l]) {
                        return false;
                    }
                    l--;
                }
            }
        }
        return true;
    }

public:
    void generateCombinations(int n) {
        if (n == 0) {
            // 输出当前组合
            for (int num : currentCombination) {
                cout << num << " ";
            }
            cout << endl;
        } else if (n > 0) {
            for (int i = 1; i <= 3; ++i) {       // 从 1 到 3 取球
                currentCombination.push_back(i); // 将球放入当前组合
                generateCombinations(n - i);     // 递归生成组合
                currentCombination.pop_back();   // 移除最后一个球以尝试其他组合
            }
        }
    }

    void ball(int n) {
        dfs(n);
    }
    vector<int> currentCombination;
    void dfs(int n) {
        if (n == 0) {
            for (int num : currentCombination) {
                cout << num << " ";
            }
            cout << endl;
        } else if (n == 1) {
            currentCombination.push_back(1);
            dfs(n - 1);
            currentCombination.pop_back();
        } else if (n == 2) {
            currentCombination.push_back(1);
            dfs(n - 1);
            currentCombination.pop_back();
            currentCombination.push_back(2);
            dfs(n - 2);
            currentCombination.pop_back();
        } else { // n>= 3
            currentCombination.push_back(1);
            dfs(n - 1);
            currentCombination.pop_back();
            currentCombination.push_back(2);
            dfs(n - 2);
            currentCombination.pop_back();
            currentCombination.push_back(3);
            dfs(n - 3);
            currentCombination.pop_back();
        }
    }
};

int main() {
    Solution solution;
        int n = 4;
    //    solution.ball(n);
        solution.generateCombinations(n);

    //    vector<int> nums = {1, 1, 2, 3, 4, 3};
    //    bool ans = solution.singlePeak(nums);
    //    cout << boolalpha << ans << endl;

    //    solution.decompose(4, "");

//    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
//    int ans = solution.findMostFrequentNumber(nums);
//    cout << ans << endl;

    return 0;
}