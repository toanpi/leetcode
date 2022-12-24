/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 */
#include "cpp_h.h"
// @lc code=start
class Solution
{
public:
    string baseNeg2(int n)
    {
        if (!n)
        {
            return "0";
        }

        int cnt = ceil(log2(n));

        if (cnt % 2)
        {
            cnt++;
        }

        string s(cnt + 1, '0');
        int val = 1 << cnt;
        int i = 0;

        while (n != 0)
        {
            n -= val;
            s[i++] = '1';
            val /= -2;
        }

        return s;
    }
};
// @lc code=end
