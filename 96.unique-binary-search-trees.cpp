/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int count(int n, int pre, vector<int> &db)
    {
        if (n == 0)
        {
            return 1;
        }

        int next = 2 * pre + 1;
        int cnt = 0;
        bool way1 = false;
        bool way2 = false;

        if (next < db.size() && !db[next])
        {
            way1 = true;
            db[next]++;
            cnt += count(n - 1, next, db);
            db[next]--;
        }

        next = pre / 2;

        if (next > 0 && !db[next])
        {
            way2 = true;
            db[next]++;
            cnt += count(n - 1, next, db);
            db[next]--;
        }

        if(way1 && way2)
        {
            db[pre / 2]++;
            db[pre * 2 + 1]++;
            cnt += count(n - 2, pre / 2, db);
            cnt += count(n - 2, pre * 2 + 1, db);
            db[pre / 2]--;
            db[pre * 2 + 1]--;
        }

        return cnt;
    }

    int numTrees(int n)
    {
        int cnt = 0;
        int size = (int)pow(2, n);
        vector<int> db(size, 0);

        for (int i = 1; i < size; i *= 2)
        {
            db[i]++;
            cnt += count(n - 1, i, db);
            db[i]--;
        }

        return cnt;
    }
};
// @lc code=end
