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
        int find = ini;          // 在中序中找到根节点
        for (; find < inj; find++) {
            if (in[find] == pre[prei]) {
                break;
            }
        }
        //a~b有b-a+1个， 从a开始有b-a+1个 是从a~
        //到b有b-a+1个 是从~b
        // pre   [prei, prei+1 ... prej]
        // in    [ini, find-1, find, find+1, inj] 左树有(find - ini)个, 右树有(inj-find)个
        // post  [posti ... postj-1, postj]
        set(pre, in, post,
            prei + 1, pre + find - ini,
            ini, find - 1,
            posti, posti + find - ini - 1); // 左子树
        set(pre, in, post,
            prei + find - ini + 1, prej,
            find + 1, inj,
            posti + find - ini, postj - 1); // 右子树
    }

public:
    /**
     * 根据先序和中序数组，返回后序数组
     * 中序遍历可以用哈希表优化, 成O(N)
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