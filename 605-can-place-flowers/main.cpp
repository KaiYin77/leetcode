#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        if (n==0) return true;

        for (int i=0; i<flowerbed.size(); i++) {
            if (flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0)) {
                flowerbed[i] = 1;
                n-=1;
                if (n==0) return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;
    std::vector<int> flowerbed{1, 0, 0, 0, 1};
    int n = 2;
    /*Test case 1*/
    bool ans_1 = sol.canPlaceFlowers(flowerbed, n);
    std::cout << ans_1 << std::endl;

    return 0;
}
