/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */
#include "cpp_h.h"

// @lc code=start
bool cmp(vector<int> x, vector<int> y)
{
    return x[0] > y[0] || (x[0] == y[0] && x[1] < y[1]);
}

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        deque<vector<int>> chain;

        sort(people.begin(), people.end(), cmp);

        for (int i = 0; i < people.size(); ++i)
        {
            chain.insert(chain.begin() + people[i][1], people[i]);
        }

        return vector<vector<int>>(chain.begin(), chain.end());
    }
};
// @lc code=end
