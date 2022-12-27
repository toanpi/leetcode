/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int total = 0;
        vector<int> sum(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            sum[i + 1] = sum[i] + nums[i];
        }

        vector<int> count(sum.back() + 1, 0);

        for (int i = 0; i < sum.size(); ++i)
        {
            if (sum[i] >= goal)
            {
                total += count[sum[i] - goal];
            }

            count[sum[i]]++;
        }

        return total;
    }
};
// @lc code=end
