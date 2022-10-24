#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    bool canReach(std::vector<int>& arr, int start) {
        return start >= 0 && start < arr.size() && arr[start] >= 0 &&
               ((arr[start] = -arr[start]) == 0 ||
                canReach(arr, start + arr[start]) ||
                canReach(arr, start - arr[start]));
    }
};
int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::vector<int> nums{4,2,3,0,3,1,2};
    int ans_1 = sol.canReach(nums, 5);
    assert(true == ans_1);

    return 0;
}

