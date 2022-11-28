/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int minStep = INT_MAX;
        int last = nums.size() - 1;
        int step = 0;
        int cur = 0;

        while (true)
        {
            if (cur + nums[cur] >= last)
            {
                minStep = min(minStep, step + (cur == last ? 0 : 1));
                break;
            }

            int maxIdx = nums[cur];

            for (int i = 1; i < nums[cur]; i++)
            {
                if (nums[cur + i] + i > nums[cur + maxIdx] + maxIdx)
                {
                    maxIdx = i;
                }
            }

            step++;
            cur += maxIdx;
        }

        return minStep;
    }
};

// @lc code=end
