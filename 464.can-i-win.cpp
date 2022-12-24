/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool check(int k, int n, vector<char> &db, int m)
    {
        if (db[n] != -1)
        {
            return db[n];
        }

        bool canWin = false;

        for (int i = 0; i < m && !canWin; ++i)
        {
            if ((n & (1 << i)) == 0)
            {
                canWin = k <= (i + 1) || !check(k - i - 1, (n | (1 << i)), db, m);
            }
        }

        return db[n] = canWin;
    }

    bool canIWin(int m, int k)
    {
        if (m * (m + 1) < k * 2)
        {
            return false;
        }
        else if (!k)
        {
            return true;
        }

        vector<char> db(1 << m, -1);
        return check(k, 0, db, m);
    }
};
// @lc code=end
