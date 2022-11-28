/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include "cpp_h.h"
// @lc code=start
class Solution
{
public:
    void combine(vector<int> &nums, int target, vector<vector<int>> &ret, vector<int> &buf, int i)
    {
        for (int k = i; k < nums.size(); k++)
        {
            if (target < nums[k])
            {
                break;
            }

            buf.push_back(nums[k]);

            if (target > nums[k])
            {
                combine(nums, target - nums[k], ret, buf, k);
            }
            else if (target == nums[k])
            {
                ret.push_back(buf);
            }

            buf.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> buf;
        int table[41] = {0};
        int len = 0;

        for(auto i: candidates) table[i]++;
        
        for (int i = 0; i < 41; i++)
        {
            while (table[i]--) candidates[len++] = i;
        }

        combine(candidates, target, ret, buf, 0);

        return ret;
    }
};

// @lc code=end
