/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        bool db[s.size() + 1];
        unordered_set<string> ws;

        memset(db, 0, sizeof(db));

        db[0] = true;

        for(auto w: wordDict)
        {
            ws.insert(w);
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (!db[i]) continue;

            for (auto w : wordDict)
            {
                if(i + w.size() <= s.size())
                {
                    if (!db[i + w.size()] && !s.compare(i, w.size(), w))
                    {
                        if(i + w.size() == s.size())
                        {
                            return true;
                        }

                        db[i + w.size()] = true;
                    }
                }
            }
        }

        return db[s.size()];
    }
};

// @lc code=end
