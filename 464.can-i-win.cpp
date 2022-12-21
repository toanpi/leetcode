/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool check(int k, vector<int> &n, unordered_map<int, vector<int>> &db)
    {
        if (db.find(k) != db.end() && equal(n.begin(), n.end(), db[k].begin() + 1))
        {
            return db[k][0] == 1;
        }

        bool canWin = false;

        for (int i = 1; i < n.size() && !canWin; ++i)
        {
            if (n[i] > 0)
            {
                n[i] = -1;

                canWin = k <= i || !check(k - i, n, db);

                n[i] = i;
            }
        }

        db[k].push_back(canWin);
        db[k].insert(db[k].begin(), n.begin(), n.end());

        return canWin;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        vector<int> n(maxChoosableInteger + 1);
        unordered_map<int, vector<int>> db;

        for (int i = 1; i <= maxChoosableInteger; ++i)
        {
            n[i] = i;
        }

        return check(desiredTotal, n, db);
    }
};
// @lc code=end
