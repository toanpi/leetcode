/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxLen = 0;
        vector<int> idx(26, -1);

        for (int i = s.size() - 1; i >= 0; --i)
        {
            idx[s[i] - 'A'] = i;
        }

        for (int i = 0; i < idx.size(); ++i)
        {
            if (idx[i] == -1)
            {
                continue;
            }

            char c = i + 'A';
            int cnt = 0;
            int n = k;
            int l = max(0, idx[i] - k);

            for (int r = max(0, idx[i] - k); r < s.size(); ++r)
            {
                if (s[r] == c || n)
                {
                    maxLen = max(maxLen, ++cnt);
                    n -= (s[r] != c) ? 1 : 0;
                }
                else
                {
                    if(k)
                    {
                        while (s[l++] == c) --cnt;
                    }
                    else
                    {
                        cnt = 0;
                    }
                }
            }
        }

        return maxLen;
    }
};
// @lc code=end
