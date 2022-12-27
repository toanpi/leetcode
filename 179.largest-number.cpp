/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
#include "cpp_h.h"

// @lc code=start

bool scmp(string x, string y)
{
    return x + y > y + x;
}

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string n = "";

        vector<string> s(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            s[i] = to_string(nums[i]);
        }

        sort(s.begin(), s.end(), scmp);

        n.reserve(200);

        for (auto k : s)
        {
            n += k;
        }

        return n[0] == '0' ? "0" : n;
    }
};
// @lc code=end
