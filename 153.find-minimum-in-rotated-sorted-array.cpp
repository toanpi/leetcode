/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        {ios_base::sync_with_stdio(false);cin.tie(nullptr);}

        int m = 0;
        int l = 0;
        int r = nums.size() - 1;
        int val = INT_MAX;
        int last = nums[r];

        while (l <= r)
        {
            m = l + (r - l) / 2;

            val = min(val, nums[m]);

            if (nums[m] <= last)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return val;
    }
};
// @lc code=end
