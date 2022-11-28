/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    void get(vector<int> &nums, int idx, vector<vector<int>> &ret, vector<int> &buf)
    {
        ret.push_back(buf);

        for (int i = idx; i < nums.size(); i++)
        {
            buf.push_back(nums[i]);
            get(nums, i + 1, ret, buf);
            buf.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ret;
        vector<int> buf;

        get(nums, 0, ret, buf);

        return ret;
    }
};
// @lc code=end
