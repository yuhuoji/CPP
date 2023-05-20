/**
 * constructor
 */
#include <iostream>
using namespace std;
class Solution {
private:
    Solution() {}
public:
    static void log() {
        cout << "Hello" << endl;
    }
};
int main() {
   Solution::log;
}