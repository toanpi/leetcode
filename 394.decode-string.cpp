/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    string decode(string s, int idx, int *lastIdx)
    {
        string out;
        int bracketCnt = 0;
        int i = idx;

        while (i < s.size() && bracketCnt >= 0)
        {
            if (isdigit(s[i]))
            {
                size_t nextIdx = 0;
                int size = stoi(s.substr(i, s.size() - i), &nextIdx);
                string buf = decode(s, i + nextIdx + 1, &i);

                while (size--) out += buf;
            }
            else if (isalpha(s[i]))
            {
                out += s[i++];
            }
            else
            {
                bracketCnt += (s[i++] == '[') ? 1 : -1;
            }
        }

        if(lastIdx) *lastIdx = i;

        return out;
    }

    string decodeString(string s)
    {
        return decode(s, 0, nullptr);
    }
};
// @lc code=end
