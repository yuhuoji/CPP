#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

  
namespace solution2894{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        return n * (n + 1) / 2 - k * (k + 1) * m;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution2894;
int main() {
    std::cout << "Leetcode " << "2894" << std::endl;
    Solution solution;

    return 0;
}