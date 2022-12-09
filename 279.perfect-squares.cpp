/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        static vector<int> db({0});

        while (db.size() <= n)
        {
            int cnt = INT_MAX;
            int m = db.size();
            int val = (int)sqrt(m);

            if(val * val == m)
            {
                cnt = 1;
            }

            for (int k = 1; k <= val && cnt > 1; k++)
            {
                cnt = min(cnt, 1 + db[m - k * k]);
            }

            db.push_back(cnt);
        }

        return db[n];
    }
};
// @lc code=end
