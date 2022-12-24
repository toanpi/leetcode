/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int solve(vector<int> &nums, bool turn, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }

        if (turn)
        {
            return max(nums[i] + solve(nums, !turn, i + 1, j),
                       nums[j] + solve(nums, !turn, i, j - 1));
        }
        else
        {
            return min(solve(nums, !turn, i + 1, j),
                       solve(nums, !turn, i, j - 1));
        }
    }

    bool PredictTheWinner(vector<int> &nums)
    {
        int sum1 = solve(nums, true, 0, nums.size() - 1);
        return 2 * sum1 >= accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end
