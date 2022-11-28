/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        {ios_base::sync_with_stdio(false);cin.tie(nullptr);}
        
        int r = nums.size() - 1;
        int l = 0;
        int m = 0;
        int val = nums[0];

        while (l <= r)
        {
            m = l + (r - l) / 2;

            long pre = m > 0 ? nums[m - 1] : LONG_MIN;
            long next = m + 1 < nums.size() ? nums[m + 1] : LONG_MIN;
            long cur = nums[m];

            if (pre < cur && cur > next)
            {
                return m;
            }
            else if (pre < cur && cur < next)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return val;
    }
};
// @lc code=end
