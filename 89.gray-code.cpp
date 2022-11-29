/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ret = {0, 1};
        int i = 1;

        while (i < n)
        {
            int val = 1 << i;

            for (int k = ret.size() - 1; k >= 0; k--)
            {
                ret.push_back(val + ret[k]);
            }

            i++;
        }

        return ret;
    }
};

// @lc code=end
