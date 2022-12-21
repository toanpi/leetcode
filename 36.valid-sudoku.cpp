/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool rows[9][10] = {0};
        bool col[9][10] = {0};
        bool area[9][10] = {0};

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int d = board[i][j];

                if (d != '.')
                {
                    int k = 3 * (i / 3) + j / 3;

                    d -= '0';

                    if (rows[i][d] || col[j][d] || area[k][d])
                    {
                        return false;
                    }

                    rows[i][d] = true;
                    col[j][d] = true;
                    area[k][d] = true;
                }
            }
        }

        return true;
    }
};
// @lc code=end
