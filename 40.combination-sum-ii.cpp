/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include "cpp_h.h"

// @lc code=start

class Solution
{
public:
    void combine(vector<int> &nums, int target, int k, vector<int> &buf, vector<vector<int>> &ret)
    {
        for (int i = k; i < nums.size();)
        {
            if (nums[i] > target) break;

            buf.push_back(nums[i]);

            if (nums[i] < target)
            {
                combine(nums, target - nums[i], i + 1, buf, ret);
            }
            else if (nums[i] == target)
            {
                ret.push_back(buf);
            }

            buf.pop_back();

            while(++i < nums.size() && nums[i] == nums[i - 1]);
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        int table[51] = {0};
        int size = 0;
        vector<int> buf;
        vector<vector<int>> ret;

        for (auto i : candidates) table[i]++;

        for (int i = 0; i < 51; i++)
        {
            while (table[i]--) candidates[size++] = i;
        }

        combine(candidates, target, 0, buf, ret);

        return ret;
    }
};

// @lc code=end
