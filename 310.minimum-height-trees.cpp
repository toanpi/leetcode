/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int height(int k, vector<unordered_map<int, int>> &db, int pre)
    {
        if (pre >= 0 && db[pre][k] >= 0)
        {
            return db[pre][k];
        }

        int h = 0;

        for (auto e : db[k])
        {
            if (e.first != pre)
            {
                h = max(h, 1 + height(e.first, db, k));
            }
        }

        return pre >= 0 ? db[pre][k] = h : h;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<unordered_map<int, int>> db(n);
        vector<int> ret(n);
        int size = 0;
        int minL = INT_MAX;

        for (auto ed : edges)
        {
            db[ed[0]].insert({ed[1], -1});
            db[ed[1]].insert({ed[0], -1});
        }

        for (int i = 0; i < db.size(); i++)
        {
            if (db[i].size())
            {
                int h = height(i, db, -1);

                if (h < minL)
                {
                    size = 0;
                    minL = h;
                }

                if (h <= minL)
                {
                    ret[size++] = i;
                }
            }
        }

        return size ? vector<int>(ret.begin(), ret.begin() + size) : vector<int>{0};
    }
};
// @lc code=end
