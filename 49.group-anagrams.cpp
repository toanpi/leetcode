/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> db;
        int cnt[26] = {0};
        string s = "";

        for (int i = 0; i < strs.size(); ++i)
        {
            s = "";
            s.reserve(strs[i].size());
            memset(cnt, 0, sizeof(cnt));

            for (auto c : strs[i])
            {
                cnt[c - 'a']++;
            }

            for (int i = 0; i < 26; ++i)
            {
                while (cnt[i]--)
                {
                    s += i + 'a';
                }
            }

            db[s].push_back(strs[i]);
        }

        vector<vector<string>> ret;

        ret.reserve(db.size());

        for (auto w : db)
        {
            ret.push_back(w.second);
        }

        return ret;
    }
};
// @lc code=end
