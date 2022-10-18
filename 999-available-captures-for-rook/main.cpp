#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int numRookCaptures(std::vector<std::vector<char>>& board) {
        int x0 = 0, y0 = 0, captures = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    x0 = i;
                    y0 = j;
                    break;
                }
            }
        }
        std::vector<std::vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto d : dir) {
            for (int x = x0 + d[0], y = y0 + d[1];
                 x >= 0 && x < 8 && y >= 0 && y < 8; x += d[0], y += d[1]) {
                if (board[x][y] == 'p') {
                    captures++;
                }
                if (board[x][y] != '.') {
                    break;
                }
            }
        }
        return captures;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::vector<std::vector<char>> board{
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','.','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };

    int ans_1 = sol.numRookCaptures(board);
    assert(3 == ans_1);

    return 0;
}
