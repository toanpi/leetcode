/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    void change(vector<vector<int>> &grid, int i, int j)
    {
        if (grid[i][j] == 0)
        {
            return;
        }

        if (grid[i][j - 1] < 0 || grid[i - 1][j] < 0 ||
            grid[i + 1][j] < 0 || grid[i][j + 1] < 0)
        {
            grid[i][j] = -1;
        }

        if (grid[i][j] == -1)
        {
            grid[i + 1][j] = -abs(grid[i + 1][j]);
            grid[i][j + 1] = -abs(grid[i][j + 1]);
            grid[i - 1][j] = -abs(grid[i - 1][j]);
            grid[i][j - 1] = -abs(grid[i][j - 1]);
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int count = 0;
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;

        for (int i = 0; i <= row; ++i)
        {
            grid[i][0] = -grid[i][0];
            grid[i][col] = -grid[i][col];
        }

        for (int i = 1; i < col; ++i)
        {
            grid[0][i] = -grid[0][i];
            grid[row][i] = -grid[row][i];
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                change(grid, i, j);
                change(grid, i, col - j);
                change(grid, row - i, j);
                change(grid, row - i, col - j);
            }
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++count;
                }
            }
        }

        return count;
    }
};
// @lc code=end
