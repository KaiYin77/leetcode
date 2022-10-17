#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        std::sort(costs.begin(), costs.end(), [](std::vector<int>& c1, std::vector<int>& c2) {
            return (c1[0]-c1[1] < c2[0]-c2[1]);
        });
        int minCost = 0;
        for (auto i=0; i < costs.size(); i++) {
            if (i < costs.size()/2) {
                minCost += costs[i][0];
            } else {
                minCost += costs[i][1];
            }
        }
        return minCost;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::vector<std::vector<int>> costs{
        {10, 20},
        {30, 200},
        {400, 50},
        {20, 20},
    };
    int ans_1 = sol.twoCitySchedCost(costs);
    assert(110 == ans_1);
    
    return 0;
}
