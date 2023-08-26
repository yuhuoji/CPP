/**
 * DFS（搜索）
 * 搜索树+剪枝，到叶节点输出当前结果并回溯
 */
#include <iomanip>
#include <iostream>
using namespace std;

int n;
bool visible[10]; // 访问标记数组
int res[10];    // 排列数组，按顺序储存当前搜索结果

void dfs(int step) {
  if (step == n + 1) {  // 边界
    for (int i = 1; i <= n; i++) {
      cout << setw(5) << res[i];  // 保留5个场宽
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (visible[i] == 0) {  // 判断数字i是否在正在进行的全排列中
      visible[i] = 1;
      res[step] = i;
      dfs(step + 1);
      visible[i] = 0;  // 这一步不使用该数 置0后允许下一步使用
    }
  }
  return;
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
