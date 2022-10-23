#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int minSwaps(std::string s) {
        int n = s.size();
        int balance = 0, swaps = 0, j = n - 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                balance++;
            } else if (s[i] == ']') {
                balance--;
            }
            if (balance == -1) {
                while (i < j && s[j] != '[') j--;
                std::swap(s[i], s[j]);
                balance = 1;
                swaps++;
            }
        }
        return swaps;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::string s("]]][[[");
    int ans_1 = sol.minSwaps(s);
    assert(2 == ans_1);

    return 0;
}
