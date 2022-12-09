/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for(auto n: nums)
        {
            minVal = min(minVal, n);
            maxVal = max(maxVal, n);
        }

        int count[maxVal - minVal + 1];

        memset(count, 0, sizeof(count));

        for(auto n: nums)
        {
            count[n - minVal]++;
        }

        for (int i = maxVal - minVal; i >= 0; i--)
        {
            if(count[i] >= k)
            {
                return i + minVal;
            }

            k -= count[i];
        }

        return 0;
    }
};
// @lc code=end
