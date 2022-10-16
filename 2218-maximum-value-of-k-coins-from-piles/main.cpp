#include<iostream>
#include<vector>
#include<cassert>

/*dp*/
//state rep:
//dp[i][j]: maximum total value of considering 0~i piles and taking j coins. 
//transfer eq:
//dp[i][j]: suppose we choose t coin in ith-pile
//dp[i][j] = max{dp[i-1][j-t] + pilesPreSum[i][t]} for t=0, 1, 2, 3..., piles[i].size()
//edge case:

// time analysis
// wrong O(n*k*k) -> right O(k * sum(piles[i].length))
class Solution {
    int dp[1003][2003] = { 0 };
    public:
        int maxValueOfCoins(std::vector<std::vector<int>> &piles, int k) {
            int n = piles.size();
            std::vector<std::vector<int>> pilesPreSum(n);
            for (int i = 0; i < piles.size(); i++) {
                int sum = 0;
                pilesPreSum[i].push_back(sum);
                for (int j = 0; j < piles[i].size(); j++) {
                    sum += piles[i][j];
                    pilesPreSum[i].push_back(sum);
                }
            }

            for (int i = 0; i < piles.size(); i++) {
                //get k coins
                for(int j = 0; j <= k; j++) {
                    //get prefix j coins
                    for(int t = 0; t <= std::min(j, (int)piles[i].size()); t++) {
                        dp[i][j] = std::max(dp[i][j], (i==0? 0: dp[i-1][j-t]) + pilesPreSum[i][t]);
                
                    }
                }
            }

            return dp[n-1][k];
        }
}; 

int main (int argc, char* argv[]) {
    /*Instance Solution*/
    Solution sol;

    /*Test Case 1*/
    std::vector<std::vector<int>> piles{
            {100},
            {100},
            {100},
            {100},
            {100},
            {100},
            {1,1,1,1,1,1,700},
    };
    int ans_tbt = sol.maxValueOfCoins(piles, 7);
    assert(ans_tbt == 706 && "Ans should be 706 !!"); 

    return 0;
}
