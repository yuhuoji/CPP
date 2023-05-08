/**
 * @date 2023-05-08
 * @file ChooseWork
 * TODO
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
/**
 *
 */
struct Job {
    int hard;  // 难度
    int money; // 报酬
    Job(){};
    Job(const int hard, const int money)
        : hard(hard), money(money) {}
};

bool cmp(Job o1, Job o2) {
    return o1.hard != o2.hard ? (o1.hard < o2.hard) : (o2.money > o1.money);
}

class ChooseWork {
private:
public:
    /**
     * 只能选择难度不大于自己能力的工作，每份工作可以有多人选择
     * 给定一个Job类型的数组job arr,表示所有的工作。
     * 给定一个int类型的数组arr,表示所有小伙伴的能力。
     * 返回int类型的数组,表示每一个小伙伴按照牛牛的标准选工作后所能获得的报酬。
     */
    static vector<int> getMoneys(vector<Job>& job, vector<int>& ability) {
        sort(job.begin(), job.end(), [](Job o1, Job o2) {
            return o1.hard != o2.hard ? (o1.hard < o2.hard) : (o2.money > o1.money);
        }); // 先按难度从小到大，再按钱从大到小排序

        cout << "hard = " << job[0].hard << ", money = " << job[0].money << endl;
        map<int, int> jobMap;                                                        // 有序表，存储<hard，money>, 难度不同且钱多的工作
        jobMap.insert(map<int, int>::value_type(job[0].hard, job[0].money));         // 加入第一个工作
        Job pre = job[0];                                                            // 第一组的工作
        for (int i = 1; i < job.size(); i++) {
            if (job[i].hard != pre.hard && job[i].money > pre.money) {               // 难度不同，且钱比之前的多
                jobMap.insert(map<int, int>::value_type(job[i].hard, job[i].money)); // 加入
                pre = job[i];
            }
        }

        // key增加，value增加
        vector<int> ans(ability.size(), 0);
        for (int i = 0; i < ability.size(); i++) {
            // 找到jobMap中小于等于能力值ability[i]的最大的key
            for (auto& entry : jobMap) {
                if (entry.first <= ability[i]) {
                    ans[i] = entry.second;
                }
            }
        }

        return ans;
    }
};
int main() {
    vector<Job> job = {Job(5, 1), Job(1, 2), Job(6, 3), Job(8, 4), Job(4, 5), Job(5, 6)};
    vector<int> ability = {3, 4, 5, 6, 7, 8};
    vector<int> ans = ChooseWork::getMoneys(job, ability);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}