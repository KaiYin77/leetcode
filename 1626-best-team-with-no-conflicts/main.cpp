#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
   public:
    int bestTeamScore(std::vector<int>& scores, std::vector<int>& ages) {
        size_t n = scores.size();
        std::vector<std::pair<int, int>> players;
        for (size_t i = 0; i < n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());

        std::vector<int> dp(n, 0);
        for (size_t i = 0; i < n; i++) {
            dp[i] = players[i].second;
            for (size_t j = 0; j < i; j++) {
                if ((players[j].first < players[i].first &&
                     players[j].second <= players[i].second) ||
                    (players[j].first == players[i].first)) {
                    dp[i] = std::max(dp[i], dp[j] + players[i].second);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::vector<int> scores{1, 3, 5, 10, 15};
    std::vector<int> ages{1, 2, 3, 4, 5};
    int ans_1 = sol.bestTeamScore(scores, ages);
    assert(34 == ans_1);
    
    return 0;
}
