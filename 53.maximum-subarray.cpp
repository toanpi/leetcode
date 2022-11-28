/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        {ios_base::sync_with_stdio(false);cin.tie(nullptr);}
        
        const int SIZE = nums.size();
        int sum = 0;
        int maxVal = INT_MIN;
        int end = 0;

        while (end < SIZE)
        {
            sum += nums[end++];

            maxVal = max(maxVal, sum);

            if (sum <= 0) sum = 0;
        }

        return maxVal;
    }
};
// @lc code=end
