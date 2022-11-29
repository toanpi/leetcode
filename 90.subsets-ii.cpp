/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    void build(vector<int> &nums, int idx, vector<vector<int>> &ret, vector<int> &buf)
    {
        ret.push_back(buf);

        for (int i = idx; i < nums.size();)
        {
            buf.push_back(nums[i]);
            build(nums, i + 1, ret, buf);
            buf.pop_back();

            while (++i < nums.size() && nums[i] == nums[i - 1]);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ret;
        vector<int> buf;

        sort(nums.begin(), nums.end());

        build(nums, 0, ret, buf);

        return ret;
    }
};

// @lc code=end
