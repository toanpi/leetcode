/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int pro = 1;
        int pro1 = 1;
        int maxVal = INT_MIN;

        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--)
        {
            pro *= nums[i];
            pro1 *= nums[j];

            maxVal = max(maxVal, max(pro, pro1));

            pro = (nums[i] == 0) ? 1 : pro;
            pro1 = (nums[j] == 0) ? 1 : pro1;
        }

        return maxVal;
    }
};
// @lc code=end
