/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_multimap<int, int> db;

        for (int i = 0; i < nums.size(); i++)
        {
            db.insert({nums[i], i});
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_multimap<int, int>::iterator key = db.find(nums[i] + k);

            if(key != db.end())
            {
                
            }
        }


    }
};
// @lc code=end
