/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */
#include "cpp_h.h"
// @lc code=start
class Solution
{
public:
    int find(char c, vector<vector<int>> &code, int idx)
    {
        for (auto i : code[c - 'a'])
        {
            if (i >= idx)
            {
                return i;
            }
        }

        return -1;
    }

    bool check(string dic, vector<vector<int>> &code)
    {
        int idx = -1;

        for (auto c : dic)
        {
            idx = find(c, code, idx + 1);

            if (idx < 0)
            {
                return false;
            }
        }

        return true;
    }

    string findLongestWord(string s, vector<string> &dictionary)
    {
        string ret = "";
        vector<vector<int>> code(26);

        for (int i = 0; i < s.size(); ++i)
        {
            code[s[i] - 'a'].push_back(i);
        }

        for (auto dic : dictionary)
        {
            if (check(dic, code) &&
                (dic.size() > ret.size() ||
                 (dic.size() == ret.size() && dic < ret)))
            {
                ret = dic;
            }
        }

        return ret;
    }
};
// @lc code=end
