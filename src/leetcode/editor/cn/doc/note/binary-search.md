二分
```c++
class BinarySearch {
public:
    // 二分，找到第一个 >= target的位置
    // 闭区间写法[l,r]
    // *第一个>=target的位置
    // 四种可以相互转换(整数)
    // 最后一个<target的位置 binarySearch(>=target) - 1
    // 第一个>target的位置 binarySearch(>=target+1)
    // 最后一个<=target的位置, 转换成binarySearch(>target) - 1, binarySearch(>=target+1) - 1
    int binarySearch(vector<int> nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) { //最后一次循环
            int m = ((r - l) >> 1) + l;
            if (target > nums[m]) {
                l = m + 1; //[l-1]一定小于target
            } else {
                r = m - 1; //[r+1]一定大于等于target
            }
        }
        // 循环结束r+1=l
        // r表示最后一个小于target的位置，l表示第一个大于等于target的位置
        return l; // 返回第一个大于等于target的位置
    }
};
```

分为闭区间，半开半闭，开区间写法。开闭区间和l和r移动相关

经典：有序数组查找target

std::lower_bound

二分答案法

1. 估计。最终答案可能的范围 是什么，可以定的粗略，反正二分不了几次

2. 分析问题的答案和给定条件之间的单调性，大部分时候只需要用到自然智慧

3. 建立一个f函数,当答案固定的情况下,判断给定的条件是否达标

4. 在最终答案可能的范围上不断二分搜索，每次用f函数判断，直到二分结束，找到最合适的答案


利用*单调性*每次排除一半的答案，缩小查找范围。找到*单调性*很重要。

f函数，用条件确定时用中间值m进行判断，排除一半的答案。

题目
34
35
875
410
162
153
33

//TODO @date 2023-10-18
1201
878