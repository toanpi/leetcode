/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string sNum = to_string(n);
        sort(sNum.begin(), sNum.end());

        for (int k = 0; k < 31; k++)
        {
            string ks = to_string(1 << k);
            sort(ks.begin(), ks.end());

            if (!sNum.compare(ks))
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
