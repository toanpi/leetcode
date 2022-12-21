/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
        {
            return 0;
        }

        bool ne = (dividend > 0) != (divisor > 0);
        int ret = 0;

        long n = abs(dividend);
        long m = abs(divisor);

        while (n >= m)
        {
            if (ret == INT_MAX)
            {
                return ne ? INT_MIN : INT_MAX;
            }

            ++ret;
            n -= m;
        }

        return ne ? -ret : ret;
    }
};
// @lc code=end
