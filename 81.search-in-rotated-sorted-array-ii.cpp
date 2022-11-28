/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool searchHelper(vector<int> &nums, int target, int l, int r)
    {
        if (l >= nums.size() || r < 0)
        {
            return false;
        }

        int m = 0;
        int middle = nums.back();
        bool part1 = target > middle;

        while (l <= r)
        {
            m = l + (r - l) / 2;

            if (nums[m] == target || nums[l] == target || nums[r] == target)
            {
                return true;
            }

            if (nums[m] == middle)
            {
                return searchHelper(nums, target, l, m - 1) ||
                       searchHelper(nums, target, m + 1, r);
            }
            else if (nums[m] < middle) // part 2
            {
                if (part1 || nums[m] > target)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else // part 1
            {
                if (nums[m] > target && part1)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }

        return false;
    }

    bool search(vector<int> &nums, int target)
    {
        return searchHelper(nums, target, 0, nums.size() - 1);
    }
};
// @lc code=end
