/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> ret;
        vector<int> code(26, 0);

        for (string w : words2)
        {
            int cnt[26] = {0};
            
            for (char c : w)
            {
                code[c - 'a'] = max(code[c - 'a'], ++cnt[c - 'a']);
            }
        }

        for (string w : words1)
        {
            int cnt[26] = {0};
            int i = 0;

            for (char c : w)
            {
                cnt[c - 'a']++;
            }

            for (; i < code.size() && cnt[i] >= code[i]; ++i);

            if (i == 26)
            {
                ret.push_back(w);
            }
        }

        return ret;
    }
};
// @lc code=end
