#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

  
namespace solution_Offer_10_I{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO 方法二：矩阵快速幂
    static const int MOD = 1000000007;
    int fib(int n) {
        if (n==0){
            return 0;
        }
        if (n==1){
            return 1;
        }
        int a=0, b= 1,sum;

        for (int i = 2; i <= n; ++i) { //fill dp[i]
            sum = (a + b) % MOD;
            a=b;
            b=sum;
        }

        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution_Offer_10_I;
int main() {
    std::cout<< "Leetcode " <<  "剑指 Offer 10- I" <<std::endl;
    Solution solution = Solution();
        int n = 5;
        cout << solution.fib(n) << endl;
    return 0;
}