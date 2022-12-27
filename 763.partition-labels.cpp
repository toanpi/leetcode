/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> db(26, 0);

        for (int i = 0; i < s.size(); ++i)
        {
            db[s[i] - 'a'] = i;
        }

        vector<int> lens;
        int i = 0;

        while (i < s.size())
        {
            int base = i;
            int size = 1;

            while (i < base + size)
            {
                size = max(size, db[s[i] - 'a'] + 1 - base);
                ++i;
            }

            lens.push_back(size);
        }

        return lens;
    }
};
// @lc code=end
