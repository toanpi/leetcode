/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<int>> db((int)matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int maxLen = 0;

        for (int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix[0].size(); j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    db[i][j] = 1 + min(db[i - 1][j - 1], min(db[i - 1][j], db[i][j - 1]));
                    maxLen = max(maxLen, db[i][j]);
                }
            }
        }

        return maxLen * maxLen;
    }
};
// @lc code=end
