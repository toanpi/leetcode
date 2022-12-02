/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int r = 0;
        int c = n - 1;

        while (r < m && c >= 0)
        {
            if (matrix[r][c] == target)
            {
                return true;
            }
            
            matrix[r][c] > target ? c-- : r++;
        }

        return false;
    }
};
// @lc code=end
