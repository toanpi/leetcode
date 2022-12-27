/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include "cpp_h.h"
// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        string s = "";
        string newPath = "";
        vector<string> dir;

        for (int i = 0; i < path.size(); ++i)
        {
            s = (path[i] != '/') ? s + path[i] : s;

            if (path[i] == '/' || i == path.size() - 1)
            {
                if (s == "..")
                {
                    if (dir.size())
                    {
                        dir.pop_back();
                    }
                }
                else if (s.size() && s != ".")
                {
                    dir.push_back(s);
                }
                s = "";
            }
        }

        for (auto k : dir)
        {
            newPath += '/';
            newPath += k;
        }

        return newPath.size() ? newPath : "/";
    }
};
// @lc code=end
