/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[i + 1][j] += min(matrix[i][j],
                                        min(matrix[i][max(j - 1, 0)],
                                            matrix[i][min(j + 1, n - 1)]));
            }
        }

        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
// @lc code=end
