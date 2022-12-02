/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s, int l, int r)
    {
        while (l < r) if (s[l++] != s[r--]) return false;

        return true;
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ret;

        for (int i = 1; i <= s.size(); i++)
        {
            bool valid = isPalindrome(s, 0, i - 1);
            
            vector<vector<string>> list = partition(s.substr(i, s.size() - i));

            if (list.size())
            {
                for (auto e : list)
                {
                    if (valid)
                    {
                        e.push_back(s.substr(0, i));
                    }
                    ret.push_back(e);
                }
            }
            else
            {
                if (valid)
                {
                    ret.push_back({s.substr(0, i)});
                }
            }
        }

        return ret;
    }
};
// @lc code=end
