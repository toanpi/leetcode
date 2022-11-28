/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include "cpp_h.h"

// @lc code=start

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ret;

        ret.push_back(intervals[0]);

        for (auto e : intervals)
        {
            auto &cur = ret.back();

            if (e[0] <= cur[1])
            {
                cur[1] = max(e[1], cur[1]);
            }
            else
            {
                ret.push_back(e);
            }
        }

        return ret;
    }
};
// @lc code=end
