/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        string ret = "";

        for (int i = s.size() - 1; i >= -1; --i)
        {
            if (i == -1 || s[i] == ' ')
            {
                int cnt = 0;

                for (int j = i + 1; s[j] && s[j] != ' '; ++j)
                {
                    ret += s[j];
                    cnt = 1;
                }

                if (cnt)
                {
                    ret += " ";
                }
            }
        }

        ret.pop_back();

        return ret;
    }
};
// @lc code=end
