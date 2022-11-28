/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> ret;
    unordered_map<int, int> table;

    for (int i = 0; i < nums.size() - 2;)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        if (table.find(-nums[j] - nums[i]) != table.end() &&
            table[-nums[i] - nums[j]] != i &&
            table[-nums[i] - nums[j]] != j)
        {
          vector<int> item = {nums[table[-nums[i] - nums[j]]], nums[j], nums[i]};

          sort(item.begin(), item.end());

          ret.push_back(item);
        }
        else
        {
          table[nums[j]] = j;
        }
      }

      while (++i < nums.size() && nums[i] == nums[i - 1]);
    }

    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());

    return ret;
  }
};
// @lc code=end
