/**
 * @date 2023-05-05
 * 347. Top K Frequent Elements
 * 前 k 个高频元素
 * std:set
 */
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) { // 比较器
        return m.second > n.second;                         // 小根堆 > , 大根堆 <
    }

    static vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences; // 哈希表<num, count>
        for (auto& v : nums) {               // 遍历nums
            occurrences[v]++;                // 词频统计
        }
        // priority_queue<_Type, _Sequence, _Compare>;
        // 存储元素pair<int, int>
        // first: num, second: count
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp); // 利用优先队列(小根堆)，将出现次数排序
        for (auto& v : occurrences) {                                                  // 遍历哈希表
            q.push(v);                                                                 // 入堆
            if (q.size() > k) {                                                        // 小根堆最多k个元素，即前k大元素.堆顶元素(门槛) < 当前元素，则堆顶出堆(最小的)，该元素入堆
                q.pop();
            }
        }
        vector<int> ans;     // 返回值
        while (!q.empty()) { // 小根堆中的元素就是前 k 大元素
            ans.emplace_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout<< Solution::topKFrequent(nums, 2) << endl;
}