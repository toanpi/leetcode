/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums, int idx, vector<vector<int>> &db, int sum)
    {
        if (sum <= 0 || idx >= nums.size() || db[idx][sum] != -1)
        {
            return sum == 0;
        }

        return db[idx][sum] = check(nums, idx + 1, db, sum - nums[idx]) || check(nums, idx + 1, db, sum);
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;

        sum = accumulate(nums.begin(), nums.end(), sum);
       
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));

        return sum % 2 ? false : check(nums, 0, dp, sum / 2);
    }
};
// @lc code=end
