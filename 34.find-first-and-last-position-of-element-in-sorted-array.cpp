/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (nums.size() && l < nums.size() && nums[l] == target)
        {
            int h = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

            return {l, h - 1};
        }
        else
        {
            return {-1, -1};
        }
    }
};
// @lc code=end
