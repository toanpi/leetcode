/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int cnt = 0;
        int tail = INT_MIN;

        sort(intervals.begin(), intervals.end());

        for(auto k: intervals)
        {
            cnt = (k[0] < tail) ? cnt + 1 : cnt;

            if (k[0] >= tail || k[1] < tail)
            {
                tail = k[1];
            }
        }

        return cnt;
    }
};
// @lc code=end
