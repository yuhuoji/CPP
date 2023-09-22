// 排序
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 选择排序
    void selectSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            swap(nums[i], nums[minIndex]);
        }
    }

    //**插入排序 容易错？
    void insertSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) { //[0...i]成为有序，将nums[i]插入之前
            int temp = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > temp) {
                nums[j + 1] = nums[j];
                j--;
            }
            // nums[j]<=temp, nums[j+1]>temp
            nums[j + 1] = temp;
        }
    }

    // 归并排序（自上而下，自下而上）
    void mergeSort1(vector<int>& nums) {
        int n = (int) nums.size();
        tmp.resize(n, 0);
        merge(nums, 0, n - 1);
    }

    vector<int> tmp; // 临时数组
    // 递归实现，自上而下
    void merge(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int middle = ((right - left) >> 1) + left;
        merge(nums, left, middle);
        merge(nums, middle + 1, right);
        // 合并 [left, middle] [middle + 1, right]
        int p = left;
        int q = middle + 1;
        int count = 0;
        while (p <= middle && q <= right) {
            if (nums[p] <= nums[q]) {
                tmp[count++] = nums[p++];
            } else {
                tmp[count++] = nums[q++];
            }
        }
        while (p <= middle) {
            tmp[count++] = nums[p++];
        }
        while (q <= right) {
            tmp[count++] = nums[q++];
        }
        // 复制回原来数组
        for (int i = 0; i < right - left + 1; ++i) { // right - left + 1 = count
            nums[left + i] = tmp[i];
        }
    }

    // TODO @date 2023-09-22
    // 归并排序，自下而上
    void mergeSort2(vector<int>& nums) {
        int n = (int) nums.size();
        for (int cur_size = 1; cur_size <= n - 1; cur_size *= 2) { // 1 2 4 8 ....
        }
    }

    // 快速排序
    void quickSort(vector<int>& nums) {
        int n = (int) nums.size();
        quickSortProcess(nums, 0, n - 1);
    }

    void quickSortProcess(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = partition(nums, left, right); //主元的选取
        quickSortProcess(nums, left, pivot - 1);
        quickSortProcess(nums, pivot + 1, right);
    }

    //TODO @date 2023-09-22
    //partition有很多种。 以nums[right]为基准，将数组分为两部分，左边小于等于基准，右边大于基准
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; ++j) { // 左侧是严格小于等于pivot的 i <= j , i和j之间是大于pivot的
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, 2, 4, 1, 4, 6, 7};
    solution.mergeSort1(nums);
    for (auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}