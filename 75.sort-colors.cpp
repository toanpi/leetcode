/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int cnt[3] = {0};
        int size = 0;

        for (auto i : nums) cnt[i]++;

        while (cnt[0]--) nums[size++] = 0;
        while (cnt[1]--) nums[size++] = 1;
        while (cnt[2]--) nums[size++] = 2;
    }
};
// @lc code=end
