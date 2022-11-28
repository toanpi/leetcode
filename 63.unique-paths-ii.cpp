/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        {ios_base::sync_with_stdio(false);cin.tie(nullptr);}

        int lastRow = matrix.size() - 1;
        int lastCol = matrix[0].size() - 1;

        if (matrix[lastRow][lastCol])
        {
            return 0;
        }

        matrix[0][0] -= 1;

        for (int i = 0; i <= lastRow; i++)
        {
            for (int j = 0; j <= lastCol; j++)
            {
                if (matrix[i][j] >= 0)
                {
                    continue;
                }
                if (j + 1 <= lastCol && matrix[i][j + 1] <= 0)
                {
                    matrix[i][j + 1] += matrix[i][j];
                }
                if (i + 1 <= lastRow && matrix[i + 1][j] <= 0)
                {
                    matrix[i + 1][j] += matrix[i][j];;
                }
            }
        }

        return abs(matrix[lastRow][lastCol]);
    }
};
// @lc code=end
