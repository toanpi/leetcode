/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */
#include "cpp_h.h"

// @lc code=start

#define add(cnt, c)  


class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        string s(a + b, ' ');
        int len = 0;
        int cntF = max(a, b);
        int cntS = min(a, b);
        char fC = a > b ? 'a' : 'b';
        char sC = fC == 'b' ? 'a' : 'b';

        while (len < s.size())
        {
            if(cntF > 0) s[len++] = fC, cntF--;
            if(cntF > 0) s[len++] = fC, cntF--;
            if(cntS > 0) s[len++] = sC, cntS--;

            if (cntS * 2 > cntF)
            {
                if (cntS > 0) s[len++] = sC, cntS--;
            }
        }

        return s;
    }
};
// @lc code=end
