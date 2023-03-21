#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {

public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        std::unordered_map<long long, long long> m;
        
        long long zeros_len = 0;
        for(size_t i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num == 0) {
                zeros_len++;
            }
            if (num != 0 || i==nums.size()-1){
                if (zeros_len !=0) {
                    if (m.find(zeros_len) == m.end()) {
                        m[zeros_len] = 1;
                    }
                    else {
                        m[zeros_len] += 1;
                    }
                }
                zeros_len = 0;
            }
        }
        long long ans = 0;
        for(auto const& v: m) {
            ans += v.second *(v.first * (v.first+1)/2); 
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;
    std::vector<int> nums{0,0,0,2,0,0};
    /*Test case 1*/
    long long ans_1 = sol.zeroFilledSubarray(nums);
    std::cout << ans_1 << std::endl;

    return 0;
}
