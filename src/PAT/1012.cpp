/**
 * @date 2023-06-08
 */

#include <algorithm>
#include <cstdio>

using namespace std;
struct student {
    int id, best; // best 1,2,3,4
    int score[4]; // ACME
    int rank[4];
} stu[2010];
int exist[1000000]; // key-id, value-stu[i]中的位置i
int flag = -1;      // flag 0,1,2,3,
bool compare(student s1, student s2) {
    return s1.score[flag] > s2.score[flag];
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m); // n行，输出第m个
    // n
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]); // id C M E
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;    // 四舍五入 A
    }

    // 计算rank
    for (flag = 0; flag <= 3; flag++) {                         // 0 1 2 3
        sort(stu, stu + n, compare);                            // 排序flag
        stu[0].rank[flag] = 1;                                  // 第一名
        for (int i = 1; i < n; i++) {
            if (stu[i].score[flag] == stu[i - 1].score[flag]) { // == 排名相同
                stu[i].rank[flag] = stu[i - 1].rank[flag];
            } else {                                            // !=
                stu[i].rank[flag] = i + 1;
            }
        }
    }

    // 计算best和exist
    for (int i = 0; i < n; i++) {
        exist[stu[i].id] = i + 1;
        stu[i].best = 0;
        int bestRank = stu[i].rank[0];
        for (int j = 1; j <= 3; j++) { // 取四个rank中最小的
            if (stu[i].rank[j] < bestRank) {
                stu[i].best = j;
                bestRank = stu[i].rank[j];
            }
        }
    }

    int id;
    // 输出M个学生的最优排名
    char subject[5] = {'A', 'C', 'M', 'E'};
    for (int i = 0; i < m; i++) {
        scanf("%d", &id);
        int tempId = exist[id];              // 检查是否存在
        if (tempId != 0) {                   // 存在
            int best = stu[tempId - 1].best; // 取出最好的
            printf("%d %c\n", stu[tempId - 1].rank[best], subject[best]);
        } else {
            printf("N/A\n");
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
