/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

#include "cpp_h.h"

// @lc code=start

bool cmp(pair<int, string> x, pair<int, string> y)
{
    return x.first > y.first ||
           (x.first == y.first && x.second < y.second);
}

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> cnt;
        vector<pair<int, string>> fre;
        vector<string> ret;

        for (auto w : words)
        {
            cnt[w]++;
        }

        for (auto n : cnt)
        {
            fre.push_back({n.second, n.first});
        }

        partial_sort(fre.begin(), fre.begin() + k, fre.end(), cmp);

        for (int i = 0; i < k; ++i)
        {
            ret.push_back(fre[i].second);
        }

        return ret;
    }
};
// @lc code=end
