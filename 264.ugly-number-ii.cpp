/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int db[n + 5];

        db[0] = 1;
        int start = 0;

        for (int i = 1; i < n; i += 4)
        {
            db[i + 0] = db[start - 1] * 2;
            db[i + 1] = db[start - 1] * 3;
            db[i + 2] = db[start - 1] * 4;
            db[i + 3] = db[start - 1] * 5;
            start = i;
        }

        return db[n - 1];
    }
};
// @lc code=end
