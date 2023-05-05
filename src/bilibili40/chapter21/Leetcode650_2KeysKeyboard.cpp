/**
 * @date 2023-05-05
 * 650. 2 Keys Keyboard
 * 质因数分解
 * 质数一定需要
 * TODO
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    /* data */
public:
    /**
     * n = a * b * c * d
     * 
     */
   int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                n /= i;
                ans += i;
            }
        }
        if (n > 1) {
            ans += n;
        }
        return ans;
    }
};
int main() {
}