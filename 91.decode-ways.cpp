/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
        {
            return 0;
        }

        vector<int> db(s.size() + 1, 0);

        db[0] = 1;

        for (int i = 0; i < s.size(); i++)
        {
            int n = s[i] - '0';

            if (n > 0)
            {
                db[i + 1] += db[i];

                if (n <= 2 && i + 1 < s.size() && n * 10 + s[i + 1] - '0' <= 26) 
                {
                    db[i + 2] += db[i];
                }
            }
        }

        return db.back();
    }
};
// @lc code=end
