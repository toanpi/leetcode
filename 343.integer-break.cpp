/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int maxB(int n, unordered_map<int, int>&db)
    {
        if (db.find(n) != db.end())
        {
            return db[n];
        }

        int mv = n;

        for (int i = 1; i <= n / 2; ++i)
        {
            mv = max(mv, i * maxB(n - i, db));
        }

        return db[n] = mv;
    }

    int integerBreak(int n)
    {
        int mv = n - 1;
        unordered_map<int, int>db;

        for (int i = 1; i <= n / 2; ++i)
        {
            mv = max(mv, i * maxB(n - i, db));
        }

        return mv;
    }
};
// @lc code=end
