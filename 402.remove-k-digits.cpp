/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        // Remove k largest numer or number with behind is 0
        string ret = "";

        for (int i = 0; i < num.size(); ++i)
        {
            while (ret.size() && num[i] < ret.back() && k > 0)
            {
                ret.pop_back();
                --k;
            }

            if (!(ret.size() == 0 && num[i] == '0'))
            {
                ret.push_back(num[i]);
            }
        }

        while(k-- && ret.size()) ret.pop_back();

        return ret.size() ? ret : "0";
    }
};
// @lc code=end
