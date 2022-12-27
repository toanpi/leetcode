/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> count(5001, 0);

        for (auto n : nums)
        {
            count[n]++;
        }

        int p = 1;

        for (int i = count.size() - 1; i >= 0; --i)
        {
            while (count[i])
            {
                if (p >= nums.size())
                {
                    p = 0;
                }

                nums[p] = i;

                p += 2;
                --count[i];
            }
        }
    }
};
// @lc code=end
