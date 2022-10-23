#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int longestArithSeqLength(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(1001, 0));
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
                result = std::max(result, dp[i][diff]);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::vector<int> nums{20,1,15,3,10,5,8};
    int ans_1 = sol.longestArithSeqLength(nums);
    assert(4 == ans_1);

    return 0;
}

//state rep.
// (0 ~ i), (diff) longest arithmetic subsequence of diff
//j i
//3,6,9,12
//dp[i][diff]
//transfer eq.
//dp[i][diff] = dp[j][diff] + 1
//result = max(result, dp[i][diff])
//edge case
// if dp[j][diff] == 0? initial should be +2
