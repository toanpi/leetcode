/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int profit(vector<int> &prices, int idx, vector<int> &db)
    {
        if (idx >= prices.size() || db[idx] >= 0)
        {
            return idx < prices.size() ? db[idx] : 0;
        }

        int pro = 0;
        int prePro = 0;

        for (int i = idx + 1; i < prices.size(); i++)
        {
            int val = prices[i] - prices[i - 1];

            if (val <= 0)
            {
                pro += max(profit(prices, i + 1, db), max(-prePro, val) + profit(prices, i, db));
                break;
            }
            else
            {
                pro += val;
                prePro = val;
            }
        }

        return db[idx] = pro;
    }

    int maxProfit(vector<int> &prices)
    {
        vector<int> db(prices.size(), -1);
        return profit(prices, 0, db);
    }

};
// @lc code=end
