/**
 * @date 2023-05-20
 * 二叉树没有重复节点
 * 根据二叉树先序和中序数组，返回后序数组
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    /**
     * 根据pre[prei...prej] in[ini...inj]，填好post[posti...postj]
     */
    void set(vector<int>& pre, vector<int>& in, vector<int>& post, int prei, int prej, int ini, int inj, int posti, int postj) {
        if (prei > prej) { // 越界
            return;
        }
        if (prei == prej) { // 只剩一个数
            post[posti] = pre[prei];
            return;
        }
        post[postj] = pre[prei]; // 先序第一个是根节点
        int find = ini;
        for (; find < inj; find++) {
            if (in[find] == pre[prei]) {
                break;
            }
        }
        //pre   [prei prei+1... prej]
        //in    [ini  (find - ini个)    find inj] find - ini左树有多少
        //post  [posti postj]
        set(pre, in, post, pre + 1, pre + find - ini,
         ini, find - 1, 
         posti, posti + find - ini-1); //左子树
        set(pre, in, post, pre + find - ini + 1, prej,
         find + 1, inj,
          posti + find - ini, postj-1); //右子树
    }

public:
    Solution(/* args */) {}
    ~Solution() {}
    /**
     * 根据先序和中序数组，返回后序数组
     */
    vector<int> getPostArray(vector<int>& pre, vector<int>& in) {
        if (pre.size() == 0 || in.size() == 0) {
            return nullptr;
        }
        int N = pre.size();
        vector<int> post(N, 0);
        set(pre, in, post, 0, N - 1, 0, N - 1, 0, N - 1);
        return post;
    }
};