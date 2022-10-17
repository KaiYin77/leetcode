#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        int x = target;
        while (x != 1 && maxDoubles > 0) {
            if (x % 2 == 0) {
                x /= 2;
                maxDoubles--;
            } else {
                x--;
            }
            moves++;
        }
        return moves + x - 1;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    int ans_1 = sol.minMoves(5, 0);
    assert(4 == ans_1);

    /*Test case 2*/
    int ans_2 = sol.minMoves(19, 2);
    assert(7 == ans_2);
    
    /*Test case 3*/
    int ans_3 = sol.minMoves(10, 4);
    assert(4 == ans_3);

    return 0;
}
