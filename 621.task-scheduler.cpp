/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n == 0)
        {
            return tasks.size();
        }

        vector<int> cnt(26, 0);

        for (auto c : tasks)
        {
            cnt[c - 'A']++;
        }

        stack<int> chain;
        int i = 0;
        int size = tasks.size();

        while (size)
        {
            if (cnt[i])
            {
                if (chain.size() && i == chain.top())
                {
                    int k = n;
                    while (k--)
                    {
                        chain.push(-1);
                    }
                }
                chain.push(i);
                --cnt[i];
                --size;
            }

            i = (i + 1) % cnt.size();
        }

        return chain.size();
    }
};
// @lc code=end
