/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */
#include "cpp_h.h"
// @lc code=start
class Solution
{
public:
    int sumR(int l, int r)
    {
        --l;
        return (r * (r + 1) / 2) - (l * (l + 1) / 2);
    }

    int get(int l, int r, vector<int> &s)
    {
        if (l >= r)
        {
            return 0;
        }

        if (l + 1 == r)
        {
            return l;
        }

        int sum = (s[r - 1] + s[l - 1]) / 2;

        for (int i = l; i <= r; ++i)
        {
            if (s[i - 1] >= sum)
            {
                return i + max(get(i + 1, r, s), get(l, i - 1, s));
            }
        }

        return 0;
    }

    int getMoneyAmount(int n)
    {
        vector<int> s(n, 0);
        int sum = 0;

        for (int i = 1; i <= n; ++i)
        {
            sum += i;
            s[i - 1] = sum;
        }

        return get(1, n, s);
    }
};

// @lc code=end
