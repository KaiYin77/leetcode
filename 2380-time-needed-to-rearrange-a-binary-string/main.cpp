#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int secondsToRemoveOccurrences(std::string s) {
        int n = s.size();
        int count = 0;  // number of zero
        int ret = 0;    // the steps of last '1' need to take
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                count++;
            } else {
                // f(j) = max(f(i) + 1, count)
                if (count > 0) {
                    ret = std::max(ret + 1, count);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::string s("0110101");
    int ans_1 = sol.secondsToRemoveOccurrences(s);
    assert(4 == ans_1);

    return 0;
}
