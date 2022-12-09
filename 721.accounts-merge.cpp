/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, vector<unordered_set<string>>> db;
        vector<vector<string>> ret;

        for (int i = 0; i < accounts.size(); i++)
        {
            auto e = db.find(accounts[i][0]);

            if (e == db.end())
            {
                unordered_set<string> cur(accounts[i].begin() + 1, accounts[i].end());
                vector<unordered_set<string>> v = {cur};
                db.insert({accounts[i][0], v});
            }
            else
            {
                bool found = false;

                for (int j = 0; j < e->second.size(); j++)
                {
                    for (int j = 1; j < accounts[i].size(); j++)
                    {
                        if (e->second[j].size() && e->second[j].find(accounts[i][j]) != e->second[j].end())
                        {
                            e->second[j].insert(accounts[i][j].begin() + 1, accounts[i][j].end());
                            found = true;
                            break;
                        }
                    }
                }

                if(!found)
                {
                    unordered_set<string> cur(accounts[i].begin() + 1, accounts[i].end());
                    e->second.push_back(cur);
                }
            }
        }

        for (auto &p : db)
        {
            vector<string> buf = {p.first};
            // ret.push_back(buf);

            for (int i = 0; i < p.second.size(); i++)
            {
                for (int j = i + 1; j < p.second.size(); j++)
                {
                    for (auto m : p.second[i])
                    {
                        if (p.second[j].find(m) != p.second[j].end())
                        {
                        }
                    }
                }
            }
        }

        return ret;
    }
};

// @lc code=end
