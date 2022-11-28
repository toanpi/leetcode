/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<int>> ret;

        ret.push_back(newInterval);

        for (auto e : intervals)
        {
            auto last = ret.back();

            if (e[1] < last[0])
            {
                ret.pop_back();
                ret.push_back(e);
                ret.push_back(last);
            }
            else if (last[1] < e[0])
            {
                ret.push_back(e);
            }
            else
            {
                ret.pop_back();
                ret.push_back({min(e[0], last[0]), max(e[1], last[1])});
            }
        }

        return ret;
    }
};
// @lc code=end
