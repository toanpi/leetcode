/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int count(vector<int> &nums, int lo, int hi, int left)
    {
        int sum = 0;

        for (int j = lo; j < hi; ++j)
        {
            if (nums[j] >= left)
            {
                sum += hi - j;
            }
            else
            {
                for (int k = j + 1; k < hi; ++k)
                {
                    if(nums[k] >= left)
                    {
                        sum += hi - k;
                        break;
                    }
                }
            }
        }

        return sum;
    }

    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        long sum = 0;
        int cnt = 0;
        int i = 0;

        for (; i < nums.size(); ++i)
        {
            if (nums[i] <= right)
            {
                ++cnt;
            }

            if (nums[i] > right)
            {
                sum += count(nums, i - cnt, i, left);
                cnt = 0;
            }
        }

        sum += count(nums, i - cnt, i, left);

        return sum;
    }
};
// @lc code=end
