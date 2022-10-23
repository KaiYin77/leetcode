#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int start_col = 0, end_col = m - 1;

        while (start_col <= end_col) {
            int mid_col = (start_col + end_col) / 2;
            int max_row = 0;
            for (int i = 0; i < n; i++) {
                max_row = mat[i][mid_col] > mat[max_row][mid_col] ? i : max_row;
            }
            bool is_right_bigger =
                mid_col + 1 <= end_col &&
                mat[max_row][mid_col] < mat[max_row][mid_col + 1];
            bool is_left_bigger =
                mid_col - 1 >= start_col &&
                mat[max_row][mid_col] < mat[max_row][mid_col - 1];

            if (!is_right_bigger && !is_left_bigger) {
                return std::vector<int>{max_row, mid_col};
            }
            if (is_right_bigger) {
                start_col = mid_col + 1;
            } else {
                end_col = mid_col - 1;
            }
        }
        return std::vector<int>{-1, -1};
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::vector<std::vector<int>> mat{
        {1, 4},
        {3, 2},
        {0, 1},
    };
    std::vector<int> ans_1 = sol.findPeakGrid(mat);
    std::cout << "[" << ans_1[0] << "," << ans_1[1] << "]\n";

    return 0;
}
