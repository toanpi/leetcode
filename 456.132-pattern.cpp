/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                if (nums[j] > nums[i])
                {
                    for (int k = j + 1; k < nums.size(); ++k)
                    {
                        if (nums[k] < nums[j] && nums[k] > nums[i])
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};
// @lc code=end
