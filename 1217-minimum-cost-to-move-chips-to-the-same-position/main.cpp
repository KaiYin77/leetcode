#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int minCostToMoveChips(std::vector<int>& position) {
        int evnCnt = 0, oddCnt = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2 == 0) {
                evnCnt++;
            } else {
                oddCnt++;
            }
        }
        return std::min(evnCnt, oddCnt);
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::vector<int> pos{2,2,2,3,3};
    int ans_1 = sol.minCostToMoveChips(pos);
    assert(2 == ans_1);

    return 0;
}
