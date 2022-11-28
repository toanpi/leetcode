/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int n, int i)
    {
        int l = i;
        int r = nums.size() - 1;
        int m = 0;
        int ret = nums.size();

        while (l <= r)
        {
            m = l + (r - l) / 2;

            if (nums[m] == n)
            {
                l = m + 1;
            }
            else if (nums[m] > n)
            {
                ret = m;
                r = m - 1;
            }
            else
            {
                ret = nums.size();
                break;
            }
        }

        return ret;
    }

    int removeDuplicates(vector<int> &nums)
    {
        int idx = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size();)
        {
            nums[idx++] = nums[i];

            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                nums[idx++] = nums[i + 1];
                i = search(nums, nums[i], i + 2);
            }
            else
            {
                i++;
            }
        }

        return idx;
    }
};
// @lc code=end
