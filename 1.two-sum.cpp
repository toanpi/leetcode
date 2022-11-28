/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> table;
    vector<int> ret;

    for (int i = 0; i < nums.size(); i++)
    {
      if (table.find(target - nums[i]) != table.end())
      {
        return {table[target - nums[i]], i};
      }
      else
      {
        table[nums[i]] = i;
      }
    }
    return {};
  }
};

// @lc code=end
