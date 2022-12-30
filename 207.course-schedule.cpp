/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool join(int x, int y, vector<unordered_set<int>>&parent)
    {
        if (x == y)
        {
            return false;
        }

        unordered_set<int> py = parent[y];

        if (parent[x].find(y) == parent[x].end())
        {
            parent[x].insert(y);
        }

        for (const auto &e : py)
        {
            if (parent[x].find(e) == parent[x].end())
            {
                if (!join(x, e, parent))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<unordered_set<int>> parent(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i)
        {
            if (!join(prerequisites[i][0], prerequisites[i][1], parent))
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
