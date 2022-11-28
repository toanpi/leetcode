/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int maxLen = 0;
        unordered_set<int> exist;

        for (auto n : nums)
        {
            exist.insert(n);
        }

        for (auto n : nums)
        {
            if (exist.find(n - 1) == exist.end())
            {
                int cnt = 1;

                while (exist.find(n + 1) != exist.end())
                {
                    n++;
                    cnt++;
                }

                maxLen = max(cnt, maxLen);
            }
        }

        return maxLen;
    }
};
// @lc code=end
