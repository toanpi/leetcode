/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        {ios_base::sync_with_stdio(false);cin.tie(nullptr);}
        
        int last = nums.size() - 1;
        int step = 0;
        int cur = 0;

        while (true)
        {
            if (cur + nums[cur] >= last)
            {
                return true;
            }

            if (nums[cur] == 0)
            {
                return false;
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

        return true;
    }
};

// @lc code=end
