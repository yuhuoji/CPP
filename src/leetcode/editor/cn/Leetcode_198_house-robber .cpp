#include "../../../../dependencies/include/bits/stdc++.h"

using namespace std;

  
namespace solution198{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //TODO @date 2023-09-17
    int rob2(vector<int>& nums) {

    }
    // 偷i: f(i) = nums[i] + max{偷i-1和i+1以外能得到的钱}

    //递归
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> isRobbed(n); //1 means robbed

        return f(nums,isRobbed,0);
    }
    //偷i位置的
//    int f(const vector<int>& nums,vector<int> isRobbed, int i){
//        int money=INT_MIN;
//        for (int j = 0; j < nums.size(); ++j) {
//            if (isRobbed[j]==0){
//                money =max(money, f(nums,isRobbed));
//            }
//        }
//
//        return money+nums[i];
//    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution198;
int main() {
    std::cout<< "Leetcode " <<  "198" <<std::endl;
    Solution solution = Solution();

    return 0;
}