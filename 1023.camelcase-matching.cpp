/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    
    bool match(string s, string pattern)
    {
        int k = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(k < pattern.size() && s[i] == pattern[k])
            {
                k++;
            }
            else if(isupper(s[i]))
            {
                return false;
            }
        }

        return k == pattern.size();
    }

    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> ret;

        for (auto s : queries)
        {
            ret.push_back(match(s, pattern));
        }

        return ret;
    }
};
// @lc code=end
