/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include "cpp_h.h"

// @lc code=start

class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    unordered_set<int> map;
    int closest = 100000; 

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
      int l = i + 1;
      int r = nums.size() - 1;

      while (l < r)
      {
        int sum = nums[l] + nums[r] + nums[i];

        if (abs(sum - target) < abs(closest - target))
        {
          closest = sum;
        }

        if (sum == target)
        {
          return closest;
        }
        else if (sum < target)
        {
          l++;
        }
        else
        {
          r--;
        }
      }
    }

    return closest;
  }
};

// @lc code=end
