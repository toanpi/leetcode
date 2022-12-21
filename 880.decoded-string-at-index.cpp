/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    string decode(vector<pair<string, int>> &code, long k)
    {
        long len = 0;
        char c = 0;

        for (int i = 0; i < code.size(); ++i)
        {
            long size = code[i].second > 0 ? code[i].second : code[i].first.size();

            if (code[i].second > 0)
            {
                if (len * size >= k)
                {
                    return decode(code, (k % len) ? (k % len) : len);
                }

                len *= size;
            }
            else
            {
                if (len + size >= k)
                {
                    return string{code[i].first[k - len - 1]};
                }

                len += size;
            }

        }

        return "";
    }

    string decodeAtIndex(string s, int k)
    {
        vector<pair<string, int>> code;
        string ns = "";

        for (int i = 0; i < s.size(); ++i)
        {
            if (isalpha(s[i]))
            {
                ns += s[i];
            }
            else if (isdigit(s[i]))
            {
                code.push_back({ns, -1});
                code.push_back({"", s[i] - '0'});
                ns = "";
            }
        }

        if (ns.size())
        {
            code.push_back({ns, -1});
        }

        return decode(code, k);
    }
};
// @lc code=end
