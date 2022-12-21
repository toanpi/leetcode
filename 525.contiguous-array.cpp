/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int cnt0 = 0;
        int cnt1 = 0;
        int maxL = 0;
        unordered_map<int, int> db = {{0, -1}};

        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] ? ++cnt1 : ++cnt0;

            if (db.find(cnt0 - cnt1) != db.end())
            {
                maxL = max(maxL, i - db[cnt0 - cnt1]);
            }
            else
            {
                db[cnt0 - cnt1] = i;
            }
        }

        return maxL;
    }
};
// @lc code=end
