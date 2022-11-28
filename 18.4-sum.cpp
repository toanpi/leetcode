/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include "cpp_h.h"
// @lc code=start

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        int size = nums.size();

        if (size < 4)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 3;)
        {
            for (int j = i + 1; j < size - 2;)
            {
                int l = j + 1;
                int r = size - 1;

                while (l < r)
                {
                    long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum == target) ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                    
                    if (sum <= target) while (++l < r && nums[l - 1] == nums[l]);

                    if (sum >= target) while (l < --r && nums[r + 1] == nums[r]);
                }

                while (++j < size - 2 && nums[j - 1] == nums[j]);
            }

            while (++i < size - 3 && nums[i - 1] == nums[i]);
        }

        return ret;
    }
};
// @lc code=end
