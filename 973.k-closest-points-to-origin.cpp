/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */
#include "cpp_h.h"
// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ret(k);
        vector<pair<long, int>> d(points.size());

        for (int i = 0; i < points.size(); ++i)
        {
            long x = points[i][0];
            long y = points[i][1];
            d[i] = make_pair(x * x + y * y, i);
        }

        sort(d.begin(), d.end());

        for (int i = 0; i < k; ++i)
        {
            ret[i] = points[d[i].second];
        }

        return ret;
    }
};
// @lc code=end
