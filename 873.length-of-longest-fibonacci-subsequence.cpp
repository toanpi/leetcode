/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        unordered_map<int, int> db;
        vector<vector<int>> longLen(arr.size(), vector<int>(arr.size(), 0));
        int maxLen = 0;

        for (int i = 0; i < arr.size(); ++i)
        {
            db[arr[i]] = i;
        }

        for (int i = 0; i < arr.size() - 1; ++i)
        {
            for (int j = i + 1; j < arr.size(); ++j)
            {
                int x0 = i;
                int x1 = j;
                int sum = arr[x0] + arr[x1];
                int len = 2;

                while (db.find(sum) != db.end())
                {
                    x0 = x1;
                    x1 = db[sum];
                    sum = arr[x0] + arr[x1];  
                    ++len;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
};
// @lc code=end
