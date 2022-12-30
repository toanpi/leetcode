/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */
#include "cpp_h.h"

// @lc code=start
#define next(i)     ((i + 1) % n)

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ret(n, -1);

        for (int i = n - 1; i >= 0; --i)
        {
            if (ret[i] == -1)
            {
                int j = next(i);

                while (j != i && nums[j] <= nums[i])
                {
                    j = ret[j] > -1 ? ret[j] : next(j);
                }

                ret[i] = j != i ? j : -1;
            }
        }

        for (int i = 0; i < ret.size(); ++i)
        {
            ret[i] = ret[i] > -1 ? nums[ret[i]] : -1;
        }

        return ret;
    }
};
// @lc code=end
