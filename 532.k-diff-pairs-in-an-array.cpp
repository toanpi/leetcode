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
        {ios_base::sync_with_stdio(false);cin.tie(nullptr);}
        
        unordered_map<int, int> db;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            db.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); i++)
        {
            auto itr = db.find(nums[i] + k);

            if (itr != db.end() && itr->second != i)
            {
                cnt++;
                db.erase(nums[i] + k);
            }
        }

        return cnt;
    }
};
// @lc code=end
