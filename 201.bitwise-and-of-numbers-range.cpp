/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ret = 0;

        while (left > 0 && right > 0)
        {
            int cL = (int)log2(left);
            int cR = (int)log2(right);
            int bitOne = 1 << cL;
        
            if (cL == cR)
            {
                ret += bitOne;
                left &= ~bitOne;
                right &= ~bitOne;
            }
            else
            {
                break;
            }
        }

        return ret;
    }
};
// @lc code=end
