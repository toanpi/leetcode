/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xors = 0;

        for (auto n : nums)
        {
            xors ^= n;
        }
        
        return xors;
    }
};
// @lc code=end
