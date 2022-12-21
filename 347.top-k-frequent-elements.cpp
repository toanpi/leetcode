/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> db;
        vector<int> ret;

        for (auto n : nums)
        {
            db[n]++;
        }

        // priority_queue<pair<int, int>> pq;

        // for (auto n : db)
        // {
        //     pq.push({n.second, n.first});

        //     if (pq.size() > db.size() - k)
        //     {
        //         ret.push_back(pq.top().second);
        //         pq.pop();
        //     }
        // }

        vector<pair<int, int>> fre;
        for (auto k : db)
        {
            fre.push_back({k.second, k.first});
        }

        // Use quicl select -> O(n)
        nth_element(fre.begin(), fre.begin() + k - 1, fre.end(), greater<>());

        for (int i = 0; i < fre.size(); ++i)
        {
            if(fre[i].first >= fre[k - 1].first)
            {
                ret.push_back(fre[i].second);
            }
        }

        // Use partial sort for vector -> n*log(k)
        // partial_sort(fre.begin(), fre.begin() + k, fre.end(), greater<>());
        // for (int i = 0; i < k; ++i)
        // {
        //     ret[i] = fre[i].second;
        // }

        return ret;
    }
};
// @lc code=end
