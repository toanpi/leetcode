/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int lR = grid.size() - 1;
        int lC = grid[0].size() - 1;
        vector<vector<int>> db(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        db[0][0] = grid[0][0];

        for (int r = 0; r <= lR; r++)
        {
            for (int c = 0; c <= lC; c++)
            {
                if (r + 1 <= lR)
                {
                    db[r + 1][c] = min(db[r + 1][c], grid[r + 1][c] + db[r][c]);
                }

                if (c + 1 <= lC)
                {
                    db[r][c + 1] = min(db[r][c + 1], grid[r][c + 1] + db[r][c]);
                }
            }
        }

        return db[lR][lC];
    }
};

// @lc code=end
