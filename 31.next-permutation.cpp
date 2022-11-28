/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    void swap(vector<int> &nums, int l, int r)
    {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }

    void nextPermutation(vector<int> &nums)
    {
        int k = nums.size() - 1;

        while (--k >= 0 && nums[k] >= nums[k + 1]);

        int order[101] = {0};
        int idx = k + 1;
        int next = k;

        for (int i = k + 1; i < nums.size(); i++)
        {
            order[nums[i]]++;
        }

        for (int i = 0; i < 101; i++)
        {
            while (order[i] > 0)
            {
                if (k >= 0 && i > nums[k] && next == k)
                {
                    next = idx;
                }

                nums[idx++] = i;
                order[i]--;
            }
        }

        if (k >= 0)
        {
            swap(nums, k, next);
        }
    }
};

// @lc code=end
