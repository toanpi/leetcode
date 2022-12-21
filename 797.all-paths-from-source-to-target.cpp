/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    void find(vector<vector<int>> &graph, int n, vector<vector<int>> &paths, vector<int> &p)
    {
        if (n >= graph.size() - 1)
        {
            p.push_back(n);
            paths.push_back(p);
            p.pop_back();
            return;
        }

        p.push_back(n);

        for (auto d : graph[n])
        {
            find(graph, d, paths, p);
        }

        p.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> paths;
        vector<int> p;

        find(graph, 0, paths, p);

        return paths;
    }
};
// @lc code=end
