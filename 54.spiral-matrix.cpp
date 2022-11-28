/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include "cpp_h.h"
// @lc code=start

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        bool hor = true;
        bool right = true;
        bool up = true;
        int sizeRow = matrix.size();
        int sizeCol = matrix[0].size();
        int row = 0;
        int col = 0;
        int len = 0;

        while (sizeRow && sizeCol)
        {
            len = hor ? sizeCol : sizeRow;
    
            if (hor)
            {
                while (len--)
                {
                    ret.push_back(matrix[row][col]);
                    col += right ? 1 : -1;
                }

                col += right ? -1 : 1;
                row += right ? 1 : -1;

                up = right;
                sizeRow--;
            }
            else
            {
                while (len--)
                {
                    ret.push_back(matrix[row][col]);
                    row += up ? 1 : -1;
                }

                row += up ? -1 : 1;
                col += up ? -1 : 1;
                
                right = !up;
                sizeCol--;
            }

            hor = !hor;
        }

        return ret;
    }
};
// @lc code=end
