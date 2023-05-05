/**
 * @date 2023-05-05
 * 可以随时展示前K个数据
 * add(k)
 * print()
 * 堆结构
 */
#include <iostream>
using namespace std;
class Solution {
private:
    class Node {
    public:
        string s;
        int times;
        Node(/* args */);
        ~Node();
    };
    class TopKRecord
    {
    private:
        /* data */
    public:
        TopKRecord(/* args */);
        ~TopKRecord();
    };
    
public:
    Solution(/* args */);
    ~Solution();
};
int main() {
}
